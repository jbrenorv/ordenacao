gcc main.c src/*.c -O3 -lm

OUTPUT_DIR="output"
mkdir -p $OUTPUT_DIR
CURRENT_TIME=$(date "+%Y.%m.%d-%H.%M.%S")
OUTPUT_FILE="$OUTPUT_DIR/output.$CURRENT_TIME.csv"

echo "algoritmo,tamanho_vetor,tipo_vetor,execucao,comparacoes,movimentos,iteracoes,tempo_ms" > $OUTPUT_FILE

tamanhos=()
for ((i=10000; i<=100000000; i+=10000)); do
    tamanhos+=($i)
done

for tamanho in "${tamanhos[@]}"; do
    for tipo in {1..3}; do
        for execucao in {1..10}; do

            ./a.out $OUTPUT_FILE $tamanho $tipo $execucao

        done
    done
done

rm a.out
