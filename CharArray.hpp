#pragma once

namespace ext
{ 

	using charArray = char*;


	char characterAt(charArray array, int number);

	void concatenate(charArray & first, charArray second);

	void append(charArray& array, char sim );

	charArray substring(charArray array, int firstPozition, int lengh);
}


