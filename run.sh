gcc main.c src/*.c -O3 -lm

OUTPUT_DIR="output"
mkdir -p $OUTPUT_DIR
CURRENT_TIME=$(date "+%Y.%m.%d-%H.%M.%S")
OUTPUT_FILE="$OUTPUT_DIR/output.$CURRENT_TIME.csv"

echo "algoritmo,tamanho_vetor,tipo_vetor,comparacoes,movimentos,tempo_ms" > $OUTPUT_FILE

TAMANHOS=(1000 10000 100000 1000000 10000000 100000000)
TIPOS=(1 2 3)

for tamanho in "${TAMANHOS[@]}"; do
    for tipo in "${TIPOS[@]}"; do

        ./a.out $OUTPUT_FILE $tamanho $tipo

    done
done

rm a.out
