#!/bin/bash

gcc src/*.c -O3 -lm

OUTPUT_DIR="output"
mkdir -p "$OUTPUT_DIR"
CURRENT_TIME=$(date "+%Y.%m.%d-%H.%M.%S")
OUTPUT_FILE="$OUTPUT_DIR/output_$CURRENT_TIME.csv"

echo "algoritmo,tamanho,tipo,execucao,comparacoes,movimentacoes,tempo_ms" > "$OUTPUT_FILE"

tamanhos=()

intervalos=(
    "1000 10000 500"
    "10000 100000 5000"
    "100000 1000000 50000"
    "1000000 10000000 500000"
    "10000000 100000001 5000000"
)

for intervalo in "${intervalos[@]}"; do
    read inicio fim passo <<< "$intervalo"
    for ((i=inicio; i<fim; i+=passo)); do
        tamanhos+=("$i")
    done
done

for tamanho in "${tamanhos[@]}"; do
    for tipo in {1..3}; do
        for execucao in {1..3}; do

            printf "\rExecutando algoritmos... Tamanho: $tamanho - Tipo: $tipo/3 - Execucao: $execucao/3"

            ./a.out "$OUTPUT_FILE" "$tamanho" "$tipo" "$execucao"

            if [ $? -ne 0 ]; then 
                printf "\nO processo finalizou com um codigo diferente de 0\n"
                printf "Cancelando testes...\n"
                rm -r "$OUTPUT_DIR"
                rm a.out
                exit 1
            fi

        done
    done
done

rm a.out
