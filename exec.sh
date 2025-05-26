#!/bin/bash

if ! command -v cpupower &> /dev/null; then
    echo "Erro: 'cpupower' não está instalado. Comando para instalar:"
    echo "sudo apt install linux-tools-common linux-tools-$(uname -r)"
    exit 1
fi
echo "Setando CPU para performance..."
sudo cpupower frequency-set -g performance

gcc main.c src/*.c -O3 -lm

OUTPUT_DIR="output"
mkdir -p "$OUTPUT_DIR"
CURRENT_TIME=$(date "+%Y.%m.%d-%H.%M.%S")
OUTPUT_FILE="$OUTPUT_DIR/output_$CURRENT_TIME.csv"

echo "algoritmo,tamanho_vetor,tipo_vetor,execucao,comparacoes,movimentos,iteracoes,tempo_ms" > "$OUTPUT_FILE"


tamanhos=()

# Define os intervalos: início fim passo
intervalos=(
    "1000 10000 1000"
    "10000 100000 10000"
    "100000 1000000 100000"
    "1000000 10000000 1000000"
    "10000000 100000001 10000000"  # Note que o fim é 100000001 para incluir 100000000
)

for intervalo in "${intervalos[@]}"; do
    read inicio fim passo <<< "$intervalo"
    for ((i=inicio; i<fim; i+=passo)); do
        tamanhos+=("$i")
    done
done


for tamanho in "${tamanhos[@]}"; do
    echo -ne "\rExecutando algoritmos para listas de tamanho $tamanho..."

    for tipo in {1..3}; do
        for execucao in {1..3}; do

            ./a.out "$OUTPUT_FILE" "$tamanho" "$tipo" "$execucao"

        done
    done
done

rm a.out
echo -e "\nSetando CPU para powersave..."
sudo cpupower frequency-set -g powersave
