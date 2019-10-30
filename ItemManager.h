//-------------------------------------------------
//	ItemManager.h.
//	10/26/2019.		created.	
//	10/26/2019.		modified.
//	by yangwenqi.
//-------------------------------------------------
#pragma once

#ifndef _ITEMMANAGER_H
#define _ITEMMANAGER_H

//-------------------------------------------------
//	headers...
//-------------------------------------------------
#include <d2d1.h>
#include <array>
#include <wincodec.h>

//-------------------------------------------------
namespace game
{
	//-------------------------------------------------
	//	type of content.
	//-------------------------------------------------
	enum class ItemType
	{
		IT_NONE = 0,//ʲô��û��
		IT_GOLD, //����
		IT_STONE,//ʯͷ
	};

	//-------------------------------------------------
	class ItemManager 
	{
	public:
		ItemManager();
		~ItemManager();
		bool initialize(ID2D1HwndRenderTarget* renderTarget);//��ʼ��
		void render(ID2D1HwndRenderTarget* renderTarget);  //��Ⱦ
		void update(ID2D1HwndRenderTarget* renderTarget); //����
		ID2D1Bitmap* getItemBitmap(ItemType type);  //������ͼƬ����ʾ����Avatar,
		//�ṩ�ӿڸ���磬�����������
		ItemType isInsectWith(int x, int y);    //��ȡ��ǰ�ĵ㣬���Ƿ�����ʲô����

	private:
		IWICImagingFactory * _pWicImgFactory = nullptr;  
		ID2D1Bitmap*				_gold_bitmap = nullptr;  // ��ȡgoldͼƬ
		std::array<std::array<ItemType, 10>, 3> _items;  // ��������װ���ӣ�ÿ��10������3��
	};

	//-------------------------------------------------
}

//-------------------------------------------------
#endif // !_ITEMMANAGER_H








