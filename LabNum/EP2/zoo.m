function zoo(n)
    D = zeros(n, n, 3); % Inicializa uma matriz de tamanho nxn com três canais (RGB)

    for i = 1:n
        for j = 1:n
           % x = (i - 1) / (j - 1);
           x=(i+j^4)/(i^2+j);
           y=j*j^(1/2)/(i-1);
        %y = i*j;
            ponto = [sin(x), sin(sin(x)+sin(y))/2, sin(x)]; % Define o valor RGB do ponto atual
            D(i, j, :) = ponto; % Atribui o valor RGB ao pixel atual
        end
    end
    
    imwrite(D, 'zoo.png');
endfunction
