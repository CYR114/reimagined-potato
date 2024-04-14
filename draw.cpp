#pragma once
#include "main.h"

double x = 100;//左上角横坐标
double y = 100;//左上角纵坐标
double width = 600;//表格宽度
double length = 600;//表格长度

//画底色
void drawBottom() {
	ege_enable_aa(true);

//	setbkcolor(EGERGB(62,66,68));
//	setfillcolor(EGERGB(62, 66, 68));
//	bar(x, y, x + width, y + length);

	int numPoints1 = 8;
	ege_point  polyPoints1[8] = { 
		{x + width / 6, y},
		{x + width * 5 / 6, y},
		{x + width, y + length / 6},
		{x + width, y + length * 5 / 6},
		{x + width * 5 / 6, y + length},
		{x + width / 6, y + length},
		{x, y + length * 5 / 6},
		{x, y + length / 6} };
	setfillcolor(EGERGB(52,54,58));
	ege_fillpoly(numPoints1, polyPoints1);
	setfillcolor(BLACK);
	fillellipse(x + width / 2, y + length / 2,width / 60 * 29 ,length / 60 * 29 );

}

//画刻度
void drawScale()
{
	setcolor(WHITE);
	setlinewidth(width / 200);
	for (size_t i = 0; i < 60; i++)
	{
		ege_line((x + width / 2) + width / 60 * 27 * cos(i * PI / 70),
				 (y + length / 2) +  length / 60 * 27  * sin(i * PI / 70),
			(x + width / 2) + width / 60 * 25  * cos(i * PI / 70),
				 (y + length / 2) +  length / 60 * 25 * sin(i * PI / 70));
		if (i % 5 == 0) {
			ege_line((x + width / 2) + (width / 60 * 29 ) * cos(i * PI / 70),
					 (y + length / 2) + (length / 60 * 29) * sin(i * PI / 70),
				(x + width / 2) + (width / 60 * 25) * cos(i * PI / 70),
					 (y + length / 2) + (length / 60 * 25) * sin(i * PI / 70));
		}
	}
	for (size_t i = 30; i < 50; i++)
	{
		ege_line((x + width / 2) + (width / 60 * 27) * cos(i * PI / 35),
				 (y + length / 2) + (length / 60 * 27) * sin(i * PI / 35),
			(x + width / 2) + (width / 60 * 25) * cos(i * PI / 35),
				 (y + length / 2) + (length / 60 * 25) * sin(i * PI / 35));
		if (i % 5 == 0) {
			ege_line((x + width / 2) + (width / 60 * 29) * cos(i * PI / 35),
					 (y + length / 2) + (length / 60 * 29 ) * sin(i * PI / 35),
				(x + width / 2) + (width / 60 * 25) * cos(i * PI / 35),
					 (y + length / 2) + (length / 60 * 25) * sin(i * PI / 35));
		}
	}
	for (size_t i = 105; i < 155; i++)
	{
		ege_line((x + width / 2) + (width / 60 * 27) * cos(i * PI / 70), 
				 (y + length / 2) + (length / 60 * 27) * sin(i * PI / 70),
			(x + width / 2) + (width / 60 * 25) * cos(i * PI / 70),
				 (y + length / 2) + (length / 60 * 25) * sin(i * PI / 70));
		if (i % 5 == 0) {
			ege_line((x + width / 2) + (width / 60 * 29) * cos(i * PI / 70),
					 (y + length / 2) + (length / 60 * 29) * sin(i * PI / 70),
				(x + width / 2) + (width / 60 * 25) * cos(i * PI / 70),
					 (y + length / 2) + (length / 60 * 25) * sin(i * PI / 70));
		}
	}
}

//输出数字
void outPutText(){

	setcolor(WHITE);
	setbkmode(TRANSPARENT);
	setfont(width / 15 , 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf((x + width / 60 * 27), (y + length / 3), "IAS");
	setfont(width / 20, 0, "楷体");
	settextjustify(LEFT_TEXT, TOP_TEXT);
	xyprintf((x + width / 60 * 29), (y + length / 10), "60");
	xyprintf((x + width / 60 * 38), (y + length / 60 * 7.5), "80");
	xyprintf((x + width / 60 * 45), (y + length / 60 * 14), "100");
	xyprintf((x + width / 60 * 49), (y + length / 60 * 23.5), "120");
	xyprintf((x + width / 60 * 49), (y + length / 60 * 33), "140");
	xyprintf((x + width / 60 * 45), (y + length / 60 * 43), "160");
	xyprintf((x + width / 60 * 37), (y + length / 60 * 49), "180");
	xyprintf((x + width / 60 * 27.8), (y + length / 60 * 52), "200");
	xyprintf((x + width / 60 * 19), (y + length / 60 * 49), "220");
	xyprintf((x + width / 60 * 11), (y + length / 60 * 43), "240");
	xyprintf((x + width / 60 * 8), (y + length / 60 * 38.5), "250");
	xyprintf((x + width / 60 * 6), (y + length / 60 * 28.5), "300");
	xyprintf((x + width / 60 * 7.8), (y + length / 60 * 18), "350");
	xyprintf((x + width / 60 * 14), (y + length / 6), "400");

}

//画粗指针
void drawPointer1(int i)
{
	//白色粗指针
	int numPoints3 = 5;
	setcolor(WHITE);
	ege_point  polyPoints3[5] = {
		{(x + width / 2) + width / 600 * 8 * cos(PI + i * PI / 180),
		(y + length / 2) + length / 600 * 8  * sin(PI + i * PI / 180)},
		{(x + width / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * cos(PI - acos(width / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
		(y + length / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * sin(PI - acos(width / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
		{(x + width / 2) + width / 60 * 21 * cos(PI / 2 + i * PI / 180),
		(y + length / 2) + length / 60 * 21 * sin(PI / 2 + i * PI / 180)},
		{(x + width / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * cos(acos(width / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
		(y + length / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * sin(acos(width / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
		{(x + width / 2) + width / 600 * 8 * cos(i * PI / 180),
		(y + length / 2) + length / 600 * 8 * sin(i * PI / 180)} };
		setfillcolor(WHITE);
		ege_fillpoly(numPoints3, polyPoints3);
		//以下依次是由内到外的三个红色填充多边形
		int numPoints4 = 4;
		ege_point  polyPoints4[4] = {
			{(x + width / 2) + sqrt((width / 60) * (length / 60) + (width / 600 * 8) * (length / 600 * 8)) *
			cos(PI - acos(width / 600 * 8 / sqrt((width / 60) * (length / 60) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60) * (length / 60) + (width / 600 * 8) * (length / 600 * 8)) *
			sin(PI - acos(length / 600 * 8 / sqrt((width / 60) * (length / 60) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8)) *
			cos(acos(width / 600 * 8 / sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8)) *
			sin(acos(length / 600 * 8 / sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8)) *
			cos(acos(width / 600 * 8 / sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8)) *
			sin(acos(length / 600 * 8 / sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8)) *
			cos(PI - acos(width / 600 * 8 / sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8)) *
			sin(PI - acos(length / 600 * 8 / sqrt((width / 15) * (length / 15) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)}};
		setfillcolor(RED);
		ege_fillpoly(numPoints4, polyPoints4);
		int numPoints5 = 4;
		ege_point  polyPoints5[4] = {
			{(x + width / 2) + sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8)) * cos(PI - acos(width / 600 * 8 / sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8)) * sin(PI - acos(length / 600 * 8 / sqrt((width / 60 * 7) * (length / 60 * 7) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8)) * cos(acos(width / 600 * 8 / sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8)) * sin(acos(length / 600 * 8 / sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8)) * cos(acos(width / 600 * 8 / sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8)) * sin(acos(length / 600 * 8 / sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8)) * cos(PI - acos(width / 600 * 8 / sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8)) * sin(PI - acos(length / 600 * 8 / sqrt((width / 6) * (length / 6) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)} };
		setfillcolor(RED);
		ege_fillpoly(numPoints5, polyPoints5);
		int numPoints6 = 4;
		ege_point  polyPoints6[4] = {
			{(x + width / 2) + sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8)) * cos(PI - acos(width / 600 * 8 / sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8)) * sin(PI - acos(length / 600 * 8 / sqrt((width / 60 * 13) * (length / 60 * 13) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8)) * cos(acos(width / 600 * 8 / sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8)) * sin(acos(length / 600 * 8 / sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * cos(acos(width / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8)) * sin(acos(length / 600 * 8 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)},
			{(x + width / 2) + sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8)) * cos(PI - acos(width / 600 * 8 / sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180),
			(y + length / 2) + sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8)) * sin(PI - acos(length / 600 * 8 / sqrt((width / 60 * 16) * (length / 60 * 16) + (width / 600 * 8) * (length / 600 * 8))) + i * PI / 180)} };
		setfillcolor(RED);
		ege_fillpoly(numPoints6, polyPoints6);
}

//画细指针
void drawPointer2(int j)
{
	setcolor(WHITE);
	int numPoints2 = 9;
		ege_point polyPoints2[9] = {
		{(x + width / 2) + width / 300 * cos(j * PI / 180),
		 (y + length / 2) + length / 300 * sin(j * PI / 180)},
		{(x + width / 2) +  sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300)) * cos(2 * PI - acos(width / 300 / sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300)) * sin(2 * PI - acos(length / 300 / sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300))) + j * PI / 180)},
		{(x + width / 2) + sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120)) * cos(2 * PI - acos(width / 120 / sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120)) * sin(2 * PI - acos(length / 120 / sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120))) + j * PI / 180)},
		{(x + width / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120)) * cos(2 * PI - acos(width / 120 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120)) * sin(2 * PI - acos(length / 120 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120))) + j * PI / 180)},
		{(x + width / 2) + width / 60 * 21* cos(PI * 1.5 + j * PI / 180),
		 (y + length / 2) + length / 60 * 21 * sin(PI * 1.5 + j * PI / 180)},
		{(x + width / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120)) * cos(PI + acos(width / 120 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120)) * sin(PI + acos(length / 120 / sqrt((width / 60 * 19) * (length / 60 * 19) + (width / 120) * (length / 120))) + j * PI / 180)},
		{(x + width / 2) + sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120)) * cos(PI + acos(width / 120 / sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120)) * sin(PI + acos(length / 120 / sqrt((width / 5) * (length / 5) + (width / 120) * (length / 120))) + j * PI / 180)},
		{(x + width / 2) + sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300)) * cos(PI + acos(width / 300 / sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300))) + j * PI / 180),
		 (y + length / 2) + sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300)) * sin(PI + acos(length / 300 / sqrt((width / 5) * (length / 5) + (width / 300) * (length / 300))) + j * PI / 180)},
		{(x + width / 2) + width / 300 * cos(PI + j * PI / 180),
		 (y + length / 2) + length / 300 * sin(PI + j * PI / 180)}
	};
	setfillcolor(WHITE);
	ege_fillpoly(numPoints2, polyPoints2);
}

//画中间的圆圈
void drawSmallCircle() {

	setcolor(EGERGB(23, 22, 24));
	setfillcolor(EGERGB(23, 22, 24));
	fillellipse((x + width / 2), (y + length / 2), width / 30, length / 30);//大

	setcolor(EGERGB(20, 20, 20));
	setfillcolor(EGERGB(20, 20, 20));
	fillellipse((x + width / 2), (y + length / 2), width / 60, length / 60);//中

	setcolor(EGERGB(30, 30, 30));
	setfillcolor(EGERGB(30, 30, 30));
	fillellipse((x + width / 2), (y + length / 2), width / 120, length / 120);//小
}


//画螺丝
void drawScrew() {
	setcolor(EGERGB(30, 30, 30));
	setfillcolor(EGERGB(30, 30, 30));
	fillellipse(x + width / 30 , y + length / 60 * 57, width / 30,length / 30);//左下角螺丝
	fillellipse(x + width / 30, y + length / 20, width / 30, length / 30);//左上角螺丝
	fillellipse(x + width / 60 * 58 ,y + length / 20, width / 30, length / 30);//右上角螺丝
	fillellipse(x + width / 60 * 58, y + length / 60 * 57, width / 30, length / 30);//右下角螺丝

	setcolor(EGERGB(3, 3, 3));
	setfillcolor(EGERGB(3, 3, 3));
	//左下角螺丝
	fillellipse(x + width / 30, y + length / 60 * 57, width / 600 * 16, length / 120);
	fillellipse(x + width / 30, y + length / 60 * 57, width / 120, length / 600 * 16);
	//左上角螺丝
	fillellipse(x + width / 30, y + length / 20, width / 600 * 16, length / 120);
	fillellipse(x + width / 30, y + length / 20, width / 120, length / 600 * 16);
	//右上角螺丝
	fillellipse(x + width / 60 * 58, y + length / 20, width / 600 * 16, length / 120);
	fillellipse(x + width / 60 * 58, y + length / 20, width / 120, length / 600 * 16);
	//右下角螺丝
	fillellipse(x + width / 60 * 58, y + length / 60 * 57, width / 600 * 16, length / 120);
	fillellipse(x + width / 60 * 58, y + length / 60 * 57, width / 120, length / 600 * 16);
}


void airPanel(int i,int j)
{
	drawBottom();
	drawScale();
	outPutText();
	drawPointer2(j);
	drawPointer1(i);
	drawSmallCircle();
	drawScrew();
}
