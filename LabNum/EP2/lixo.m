function decompress(compressedImg, method, k, h)
  imagem = imread(compressedImg);
  [altura, largura, p] = size(imagem);
  altura
  largura

  if method == 1 %bilinear
    %n = altura + (altura - 1) * k;
    %n
    D = expandMatrix(imagem, altura, k);
    [n, l, pn] = size(D);
    n
    l
    for canal = 1:3
      for i = 1:(h-1):(n)
        for j = 1:(h-1):(n)
        
          % Calcular pontos dados das bordas
          ponto00 = D(i, j, canal);
          ponto10 = D(min(i + (h-1),n), j, canal);
          ponto01 = D(i, min(j + (h-1),n), canal);
          ponto11 = D(min(i + (h-1),n), min(j + (h-1),n), canal);

          matrizA = [1, 0, 0, 0; 1, 0, h, 0; 1, h, 0, 0; 1, h, h, h^2];
          matrizA_inv = inv(matrizA);

          % Preencher os pixels criados com a expansão do quadrado
          vetorB = [ponto00; ponto01; ponto10; ponto11];
          vetorB = double(vetorB);
          vetorX = matrizA_inv * vetorB;
          for p = i:(i + (h-1))
            for r = j:(j + (h-1))
              D(p, r, canal) = vetorX(1, 1) + vetorX(2, 1) * ((p - i) / (h-1)) * h + vetorX(3, 1) * ((r - j) / (h-1)) * h + vetorX(4, 1) * (((p - i) / (h-1)) * h) * (((r - j) / (h-1)) * h);
            endfor
          endfor
        endfor
      endfor
    endfor
  endif
  if method == 2 %bicubic
    %n = altura + (altura - 1) * k;
    %n
    %D = expandMatrix(imagem, n, k);
    D = expandMatrix(imagem, altura, k);
    [n, l, pn] = size(D);
    n
    for canal = 1:3
      for i = 1:(h-1):(n)
        for j = 1:(h-1):(n)
        
        F00 = D(i, j, canal);
        F01 = D(i, min(j+(h-1),n), canal);
        F02 = derivate(D,i,j, 1 , h,canal); 
        F03 = derivate(D,i,min(j+(h-1),n), 1 , h,canal);
        F10 = D(min(i+(h-1),n), j, canal);
        F11 = D(min(i+(h-1),n), min(j+(h-1),n), canal);
        F12 = derivate(D,min(i+(h-1),n),j, 1 , h,canal);
        F13 = derivate(D,min(i+(h-1),n),min(j+(h-1),n), 1 , h,canal);
        F20 = derivate(D,i,j, 0 , h,canal);
        F21 = derivate(D,i,min(j+(h-1),n), 0 , h,canal);
        F22 = derivate(D,i,j, 2 , h,canal);
        F23 = derivate(D,i,min(j+(h-1),n), 2 , h,canal);
        F30 = derivate(D,min(i+(h-1),n),j, 0 , h,canal);
        F31 = derivate(D,min(i+(h-1),n),min(j+(h-1),n), 0 , h,canal);
        F32 = derivate(D,min(i+(h-1),n),j, 2 , h,canal);
        F33 = derivate(D,min(i+(h-1),n),min(j+(h-1),n), 2 , h,canal);

        MatrizF = double([F00,F01,F02,F03;F10,F11,F12,F13;F20,F21,F22,F23;F30,F31,F32,F33]);
        

          % Calcular coeficientes da matriz B-spline
          matrizB = double([1, 0, 0, 0; 1, h, h^2, h^3; 0, 1, 0, 0; 0, 1, 2*h, 3*(h^2)]);
          matrizB_inv = inv(matrizB);
          matrizTB = matrizB';
          matrizTB_inv = inv(matrizTB);

          resultado = matrizB_inv * MatrizF * matrizTB_inv;


          
          for x = i:(min(i + (h-1),n))
            for y = j:(min(j + (h-1),n))

              if D(x,y,canal) == 0    
                % Vetor dos termos (x - xi)
                vetor_x = [1, (x - i), (x - i)^2, (x - i)^3];
                vetor_y = [1, (y - j), (y - j)^2, (y - j)^3];

                % Multiplicação da matriz resultado pelo vetor
                ponto = vetor_x * resultado * vetor_y';

                  D(x,y,canal) = ponto;
              endif
              
            endfor
          endfor
          
        
        endfor
      endfor
    endfor
  endif
  imwrite(D, 'decompressed.png');
endfunction

function D = expandMatrix(imagem, n, k)
  
  for i = 1:n
    xi = (i - 1) * (k + 1) + 1;
    xip = min((min(i + 1, n) - 1) * (k + 1) + 1, n + (n - 1) * k);
    
    for j = 1:n
      yj = (j - 1) * (k + 1) + 1;
      yjp = min((min(j + 1, n) - 1) * (k + 1) + 1, n + (n - 1) * k);

      D(xi:xip, yj:yjp, 1) = imagem(i, j, 1);
      D(xi:xip, yj:yjp, 2) = imagem(i, j, 2);
      D(xi:xip, yj:yjp, 3) = imagem(i, j, 3);
    endfor
  endfor
endfunction


function der = derivate(D, x, y, modo, h, canal)
  [altura, largura, ~] = size(D);
  
  if x >= 1 && x <= largura && y >= 1 && y <= altura
    if modo == 0 % derivada em x
      if (x - (h - 1)) < 1 || (x + (h - 1)) > largura
        der = D(x, y, canal);
      else
        der = (D(min(x + (h - 1),altura), y, canal) - D(x - (h - 1), y, canal)) / (2 * h);
      endif
    elseif modo == 1 % derivada em y
      if (y - (h - 1)) < 1 || (y + (h - 1)) > altura
        der = D(x, y, canal);
      else
        der = (D(x, min(y + (h - 1),altura), canal) - D(x, y - (h - 1), canal)) / (2 * h);
      endif
    elseif modo == 2 % derivada em x e y
      if (x - (h - 1)) < 1 || (x + (h - 1)) > largura || (y - (h - 1)) < 1 || (y + (h - 1)) > altura
        der = D(x, y, canal);
      else
        der1 = derivate(D, min(x + (h - 1),altura), y, 1, h, canal);
        der2 = derivate(D, x - (h - 1), y, 0, h, canal);
        der = (der1 - der2) / (2 * h);
      endif
    endif
  elseif x < 1 && modo == 0 % derivada em x com x < 1
    der = (D(2, y, canal) - D(1, y, canal)) / h;
  elseif y < 1 && modo == 1 % derivada em y com y < 1
    der = (D(x, 2, canal) - D(x, 1, canal)) / h;
  elseif x > largura && modo == 0 % derivada em x com x > largura
    der = (D(x, y, canal) - D(x - (h - 1), y, canal)) / h;
  elseif y > altura && modo == 1 % derivada em y com y > altura
    der = (D(x, y, canal) - D(x, y - (h - 1), canal)) / h;
  endif
endfunction
