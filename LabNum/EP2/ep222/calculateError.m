function err =  calculateError(originalImg, decompressedImg)
   oImg = double(imread(originalImg));
   dec = double(imread(decompressedImg));
   
   origRed = oImg(:,:,1);
   origGreen = oImg(:,:,2);
   origBlue = oImg(:,:,3);


   decRed = dec(:,:,1);
   decGreen = dec(:,:,2);
   decBlue = dec(:,:,3);


   
   errR = (norm(origRed - decRed))/norm(origRed);
   errG = (norm(origGreen - decGreen))/norm(origGreen);
   errB = (norm(origBlue - decBlue))/norm(origBlue);
   err = (errR + errG + errB)/3;
   disp(err);
endfunction