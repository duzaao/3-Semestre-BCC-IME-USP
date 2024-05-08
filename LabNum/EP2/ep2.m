%compress('c.png',10);

%for i = 1:100
%    original= imread('leao.png');
%    [altura, largura, profundidade] = size(original);
%   if mod(altura + i, i + 1) == 0
%       disp(i);
%   endif
%endfor

%decompress('compressed.png',1,10,4);
%a = calculateError('zoo.png', 'decompressed.png');
%
%function err =  calculateError(originalImg, decompressedImg)
%   orig = double(imread(originalImg));
%   dec = double(imread(decompressedImg));
%   
%   origR = orig(:,:,1);
%   origG = orig(:,:,2);
%   origB = orig(:,:,3);
%   decR = dec(:,:,1);
%   decG = dec(:,:,2);
%   decB = dec(:,:,3);
%   
%   errR = (norm(origR - decR))/norm(origR);
%   errG = (norm(origG - decG))/norm(origG);
%   errB = (norm(origB - decB))/norm(origB);
%   err = (errR + errG + errB)/3;
%   disp(err);
%endfunction


%compress('zoo.png',2);

%for i = 400:1000
%  if mod(i + 7, 7 + 1) == 0
%  zoo(i);
%      for j = 1:10
%    compress('zoo.png',j);
%    original= imread('compressed.png');
%    [altura, largura, profundidade] = size(original);
%  if mod(altura + j, j + 1) == 0
%      if j == 7 
%      disp(j);
%      endif
%  endif
%    endfor
%  endif
%endfor

%zoo(449);
%compress('zoo.png',7);
%decompress('compressed.png',2,1,3);
%decompress('decompressed.png',2,1,3);
%decompress('decompressed.png',2,1,3);




%
%a = calculateError('zoo.png', 'decompressedx.png');
%
%
%a = calculateError('zoo.png', 'decompressedy.png');
%
%
%a = calculateError('zoo.png', 'decompressedzbl.png');
%
a = calculateError('zoo.png', 'decompressed.png');

function err =  calculateError(originalImg, decompressedImg)
   orig = double(imread(originalImg));
   dec = double(imread(decompressedImg));
   
   origR = orig(:,:,1);
   origG = orig(:,:,2);
   origB = orig(:,:,3);
   decR = dec(:,:,1);
   decG = dec(:,:,2);
   decB = dec(:,:,3);
   
   errR = (norm(origR - decR))/norm(origR);
   errG = (norm(origG - decG))/norm(origG);
   errB = (norm(origB - decB))/norm(origB);
   err = (errR + errG + errB)/3;
   disp(err);
endfunction


compress('leao.png',10);
decompress('compressed.png',1,10,4);

a = calculateError('leao.png', 'decompressed.png');