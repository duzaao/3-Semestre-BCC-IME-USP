#!/bin/bash

DNA_aleatorio () {
    letras=("A" "G" "C" "T")

    texto=""

    for((i=0 ; i<$1 ; i++)); do
        letra_aleatoria=$(shuf -n 1 -e "${letras[@]}")
        texto="$texto$letra_aleatoria"
    done
}

corta() {
  texto="$1"
  tamanho_total="${#texto}"
  k="$2"
  contador=0

  while [ "${#texto}" -gt 0 ]; do
    # Gera um índice aleatório para dividir o texto
    indice=$(($2 + RANDOM % $3))
    

    # Extrai a parte do texto até o índice gerado
    parte="${texto:0:indice+1}"

    # Verifica se é a primeira parte a ser dividida
    if [ "${#texto}" -eq "$tamanho_total" ]; then
      echo "${parte}${texto:indice+1: k}"
    else
      # Imprime a parte com k letras adicionadas após ela
      echo "${parte}${texto:indice+1: k}"
    fi

    # Remove a parte extraída do texto original
    texto="${texto#"$parte"}"

    # Remove possíveis espaços em branco no início do texto
    texto="${texto#"${texto%%[![:space:]]*}"}"

    # Incrementa o contador
    contador=$((contador + 1))
  done
  contador=$((contador + 1))

  # Imprime a quantidade de strings divididas
  echo "Total de strings divididas: $contador"
}

tamanho=40

DNA_aleatorio $tamanho 3
echo $texto
corta $texto 1 10
