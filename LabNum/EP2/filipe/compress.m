function compress(originalImg, k)
  original= imread(originalImg);
  img = original;
  [altura, largura, profundidade] = size(img);

  img = img(1:(k+1):altura, 1:(k+1):largura, :);
  imwrite(img, 'compress.png');
endfunction

