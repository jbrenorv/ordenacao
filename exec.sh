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
for ((i=10000; i<=100000000; i+=10000)); do
    tamanhos+=("$i")
done

for tamanho in "${tamanhos[@]}"; do
    echo -ne "\rExecutando algoritmos para listas de tamanho $tamanho..."

    for tipo in {1..3}; do
        for execucao in {1..10}; do

            # Executa com prioridade máxima e fixo no núcleo 2
            sudo nice -n -20 taskset -c 2 ./a.out "$OUTPUT_FILE" "$tamanho" "$tipo" "$execucao"

        done
    done
done

rm ordenacao
echo -e "\nSetando CPU para powersave..."
sudo cpupower frequency-set -g powersave
