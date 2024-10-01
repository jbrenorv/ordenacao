gcc src/*.c -lm

# deletes the output file if it exists
OUTPUT_FILE="output.csv"
if [ -f "$OUTPUT_FILE" ]; then
    rm $OUTPUT_FILE
fi

echo "algorithm,array_size,array_type,comparisons,movements,time_ms" > $OUTPUT_FILE

SIZES=(100 1000 10000 100000) # 1000000 10000000 100000000)
TYPES=(1 2 3)

# run the algorithms for all sizes and types
for size in "${SIZES[@]}"; do
    for type in "${TYPES[@]}"; do

        ./a.out $size $type

    done
done
