#!/bin/bash

# Número de vezes que o executável será rodado
MODE=$1
FILE=$2
TIPE=$3
N=100
OUTPUT=FULL

if [ $# -ge 3 ]; then
    N=$4
fi

if [ $# == 4 ]; then
    OUTPUT=$5
fi

# Variáveis para armazenar o tempo mínimo, tempo máximo e soma dos tempos
MIN=1000000 # Valor inicial grande o suficiente para garantir que o primeiro tempo seja menor
MAX=0
SUM=0

# Executa o executável N vezes e calcula os tempos
for i in $(seq 1 $N); do


  # Executa o executável e redireciona a saída para /dev/null
  tempo=$( { time ./EP ${FILE} ${MODE} ${TIPE}; } 2>&1 | grep real | awk '{print $2}' )
  # Remove vírgulas e substitui por ponto
  tempo=$(echo "$tempo" | tr ',' '.')

# Extract minutes and seconds
#minutos=$(echo "$tempo" | cut -d 'm' -f 1 | cut -c 2-)
#segundos=$(echo "$tempo" | cut -d 'm' -f 2 | cut -d 's' -f 1)

# Convert minutes and seconds to seconds with up to 5 decimal places
#tempo_seg=$(echo "($minutos * 60) + $segundos" | bc -l)

  

 #Adiciona o tempo à soma dos tempos
 #SUM=$(echo "$SUM + $tempo_seg" | bc -l)
 echo "${TIPE} : ${tempo}"
done


 #   AVG=$(echo "scale=5; $SUM / $N" | bc -l)
  #  AVG=$(printf $AVG)
#echo $tempo


# Imprime os resultados

#if [ ${OUTPUT} == FULL ]; then
#    echo "${MIN}, ${AVG}, ${MAX}"
#else
    #echo "${TIPE} : ${AVG}"
#fi