function D = expandMatrix(img, n, k) 
  for i=1:(n+(n-1)*k)
    for j=1:(n+(n-1)*k)
      if(rem(i, k+1) == 1 && rem(j,k+1) == 1)
        D(i,j,:) = img((i-1)/(k+1) + 1, (j-1)/(k+1) + 1, :);
      endif
    endfor
  endfor
  D
endfunction
       