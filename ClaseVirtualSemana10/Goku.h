#pragma once
#pragma once
#include<string.h>
using namespace System;
using namespace System::Drawing;
class Goku
{
private:
	int x, y, w, h, indice;
	char* path;//para la ruta de las imagenes
public:
	Goku(void);
	Goku(int px, int py);
	void Mostrar(Graphics ^gr);
	void Mover(Graphics ^gr);
	void Eliminar(Graphics ^gr);
	~Goku(void);
};
Goku::Goku()
{
	x = y = w = h = indice = 0;
	path = nullptr;
}
Goku::Goku(int px, int py)
{
	x = px;
	y = py;
	indice = 1;
	path = new char[50];
	strcpy(path, "goku/frame_0.gif");//copia una cadena a otra
	//strcpy(destino, origen);
	//cargar la imagen
	Bitmap^imagen = gcnew Bitmap(gcnew System::String(path));
	w = imagen->Width;
	h = imagen->Height;
}
void Goku::Mostrar(Graphics ^gr)
{
	if (indice == 0)strcpy(path, "goku/frame_0.gif");
	if (indice == 1)strcpy(path, "goku/frame_1.gif");
	if (indice == 2)strcpy(path, "goku/frame_2.gif");
	if (indice == 3)strcpy(path, "goku/frame_3.gif");
	if (indice == 4)strcpy(path, "goku/frame_4.gif");
	if (indice == 5)strcpy(path, "goku/frame_5.gif");
	if (indice == 6)strcpy(path, "goku/frame_6.gif");
	if (indice == 7)strcpy(path, "goku/frame_7.gif");
	if (indice == 8)strcpy(path, "goku/frame_8.gif");
	//cargar la imagen
	Bitmap ^imagen = gcnew Bitmap(gcnew System::String(path));
	w = imagen->Width;
	h = imagen->Height;
	gr->DrawImage(imagen, x, y);//dibuja la imagen en x,y


}
void Goku::Mover(Graphics ^gr)
{
	Eliminar(gr);
	indice++;
	if (indice > 8)indice = 1;

	Mostrar(gr);
}
void Goku::Eliminar(Graphics ^gr)
{
	gr->FillRectangle(Brushes::White, x, y, w, h);
}

Goku::~Goku()
{
	delete[]path;
}