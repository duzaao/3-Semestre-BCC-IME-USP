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
  if method == 2
    
    n = altura + (altura - 1) * k;
    D = expandMatrix(imagem, n, k);
    for canal = 1:3
      for i = 1:(k + 1):(n - (k + 1))
        for j = 1:(k + 1):(n - (k + 1))
          % Calcular valores dos pontos
          ponto00 = D(i, j, canal);
          ponto01 = D(i , j + (k + 1), canal);
          ponto10 = D(i + (k + 1), j, canal);
          ponto11 = D(i + (k + 1), j + (k + 1), canal);
          ponto12 = D(i + (k + 1), j + (k + 2), canal);
          ponto20 = D(i + (k + 2), j, canal);
          ponto21 = D(i + (k + 2), j + (k + 1), canal);
          ponto22 = D(i + (k + 2), j + (k + 2), canal);
           
          % Cálculo das derivadas
          derivadaX00 = (ponto01 - ponto00) / h;
          derivadaX01 = (ponto11 - ponto10) / h;
          derivadaX02 = (ponto12 - ponto11) / h;
          derivadaX03 = (ponto11 - ponto12) / h;
         
          derivadaX10 = (ponto10 - ponto00) / h;
          derivadaX11 = (ponto11 - ponto01) / h;
          derivadaX12 = (ponto12 - ponto02) / h;
          derivadaX13 = (ponto21 - ponto20) / h;
         
          derivadaY00 = (ponto10 - ponto00) / h;
          derivadaY01 = (ponto11 - ponto01) / h;
          derivadaY02 = (ponto12 - ponto02) / h;
          derivadaY03 = (ponto12 - ponto11) / h;
         
          derivadaY10 = (ponto20 - ponto00) / h;
          derivadaY11 = (ponto21 - ponto01) / h;
          derivadaY12 = (ponto22 - ponto02) / h;
          derivadaY13 = (ponto22 - ponto21) / h;
      
          mx = [derivadaX00, derivadaX01, derivadaX02, derivadaX03;
              derivadaX10, derivadaX11, derivadaX12, derivadaX13;
              0, 1, 0, 0;
              0, 0, 1, 0];
          my = [derivadaY00, derivadaY01, derivadaY02, derivadaY03;
              derivadaY10, derivadaY11, derivadaY12, derivadaY13;
              0, 0, 1, 0;
              0, 0, 0, 1];
          vetorD = [ponto00; ponto10; derivadaX00; derivadaY00];
          a = inv(mx) * vetorD;
          b = inv(my) * vetorD;
          
          for p = i:(i + (k + 1))
            for r = j:(j + (k + 1))
              x = (p - i) / (k + 1) * h;
              y = (r - j) / (k + 1) * h;
              D(p, r, canal) = a(1,1) + a(2,1) * x + a(3,1) * x^2 + a(4,1) * x^3 + b(2,1) * y + b(3,1) * y^2 + b(4,1) * y^3 + a(2,1)*b(3,1) * x*y + a(3,1)*b(2,1) * x*y + a(3,1)*b(3,1) * x^2*y + a(4,1)*b(2,1) * x^3*y + a(2,1)*b(4,1) * x*y^2 + a(3,1)*b(4,1) * x^2*y^2 + a(4,1)*b(3,1) * x^3*y^2 + a(4,1)*b(4,1) * x^3*y^3;
            endfor
          endfor 
        endfor
      endfor
    endfor
  endif


  pdi_expandido = uint8(D);
  imwrite(pdi_expandido, 'imagemExpandida.jpg');
  imshow(pdi_expandido);

endfunction