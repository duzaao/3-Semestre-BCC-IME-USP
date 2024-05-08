  function decompress(compressedImg, method, k, h)
  imagem = imread(compressedImg);
  [altura, largura, p] = size(imagem);
  altura

  if method == 1 %bilinear
    n = altura + (altura - 1) * k;
    n
    D = expandMatrix(imagem, n, k);

    for canal = 1:3
      for i = 1:(k + 1):(n - (k + 1))
        for j = 1:(k + 1):(n - (k + 1))
        
          % Calcular pontos dados das bordas
          ponto00 = D(i, j, canal);
          ponto10 = D(i + (k + 1), j, canal);
          ponto01 = D(i, j + (k + 1), canal);
          ponto11 = D(i + (k + 1), j + (k + 1), canal);

          matrizA = [1, 0, 0, 0; 1, 0, h, 0; 1, h, 0, 0; 1, h, h, h^2];
          matrizA_inv = inv(matrizA);

          % Preencher os pixels criados com a expansão do quadrado
          vetorB = [ponto00; ponto01; ponto10; ponto11];
          vetorB = double(vetorB);
          vetorX = matrizA_inv * vetorB;
          for p = i:(i + (k + 1))
            for r = j:(j + (k + 1))
              D(p, r, canal) = vetorX(1, 1) + vetorX(2, 1) * ((p - i) / (k + 1)) * h + vetorX(3, 1) * ((r - j) / (k + 1)) * h + vetorX(4, 1) * (((p - i) / (k + 1)) * h) * (((r - j) / (k + 1)) * h);
            endfor
          endfor
        endfor
      endfor
    endfor
  endif
  if method == 2 %bicubic
    n = altura + (altura - 1) * k;
    D = expandMatrix(imagem, n, k);

    for canal = 1:3
      for i = 1:(k + 1):(n - (k + 1))
        for j = 1:(k + 1):(n - (k + 1))
        
          % Calcule os pontos para a bicúbica
          ponto00 = D(i, j, canal);
          ponto01 = D(i, j + (k + 1), canal);
          ponto02 = D(i, j + 2 * (k + 1), canal);
          ponto03 = D(i, j + 3 * (k + 1), canal);
          ponto10 = D(i + (k + 1), j, canal);
          ponto11 = D(i + (k + 1), j + (k + 1), canal);
          ponto12 = D(i + (k + 1), j + 2 * (k + 1), canal);
          ponto13 = D(i + (k + 1), j + 3 * (k + 1), canal);
          ponto20 = D(i + 2 * (k + 1), j, canal);
          ponto21 = D(i + 2 * (k + 1), j + (k + 1), canal);
          ponto22 = D(i + 2 * (k + 1), j + 2 * (k + 1), canal);
          ponto23 = D(i + 2 * (k + 1), j + 3 * (k + 1), canal);
          ponto30 = D(i + 3 * (k + 1), j, canal);
          ponto31 = D(i + 3 * (k + 1), j + (k + 1), canal);
          ponto32 = D(i + 3 * (k + 1), j + 2 * (k + 1), canal);
          ponto33 = D(i + 3 * (k + 1), j + 3 * (k + 1), canal);

          matrizA = [1, 0, 0, 0, 0, 0, 0, 0; 1, 0, h, h^2, h^3, 0, 0, 0; 1, h, h^2, h^3, 0, 0, 0, 0; 1, h, 0, 0, 0, 0, 0, 0; 1, 0, 0, 0, 0, h^3, h^2, h; 1, 0, h, h^2, h^3, 0, 0, 0; 1, h, h^2, h^3, 0, 0, 0, 0; 1, h^3, h^2, h, 0, 0, 0, 0];
          matrizA_inv = inv(matrizA);

          % Preencher os pixels criados com a expansão do quadrado
          vetorB = [ponto00; ponto01; ponto02; ponto03; ponto10; ponto11; ponto12; ponto13; ponto20; ponto21; ponto22; ponto23; ponto30; ponto31; ponto32; ponto33];
          vetorB = double(vetorB);
          vetorX = matrizA_inv * vetorB;
          for p = i:(i + (k + 1))
            for r = j:(j + (k + 1))
              D(p, r, canal) = vetorX(1, 1) + vetorX(2, 1) * ((p - i) / (k + 1)) * h + vetorX(3, 1) * ((p - i) / (k + 1)) * h * h + vetorX(4, 1) * ((p - i) / (k + 1)) * h * h * h + vetorX(5, 1) * ((r - j) / (k + 1)) * h + vetorX(6, 1) * ((r - j) / (k + 1)) * h * h + vetorX(7, 1) * ((r - j) / (k + 1)) * h * h * h + vetorX(8, 1) * (((p - i) / (k + 1)) * h) * (((r - j) / (k + 1)) * h);
            endfor
          endfor
        endfor
      endfor
    endfor
  endif
    imwrite(D, 'decompress.png');
endfunction

function D = expandMatrix(imagem, n, k) 
  for i=1:n
    for j=1:n
      if(rem(i, k+1) == 1 && rem(j,k+1) == 1)
        D(i,j,:) = imagem((i-1)/(k+1) + 1, (j-1)/(k+1) + 1, :);
      endif
    endfor
  endfor
  size(D)(1)
endfunction


