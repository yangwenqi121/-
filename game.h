//------------------------------------------
//game.h   
//10/27/2019   created
//10/27/2019   modified
//10/27/2019   bu yangwenqi
//------------------------------------------
#include <Windows.h>
#include <memory>
#include "Avatar.h"
#include <d2d1.h>
#include <d2d1helper.h>
#include <dwrite.h>
#include <wincodec.h>
#include <unordered_map>  //��ϣmap����������
#include "ItemManager.h"
#include "ScoreManager.h"
//------------------------------------------
#pragma once
#ifndef _GAME_H
#define _GAME_H
//------------------------------------------
namespace game
{
	//------------------------------------------
	enum class  INPUTBUTTON
	{
		IB_Space=0,
	};
	//------------------------------------------
	//------------------------------------------
	/*ȫ�ֶ��� ,����ģʽ�����ģʽ*/
	class Game 
	{
	public:
		static Game * getSingleton(void); //������̬������
		static void destroySingleton(void); //����
		bool initialize(HWND hWnd); //��ʼ��
		LRESULT processEvent(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam); //�¼�
		bool frame(void);
		bool checkInput(INPUTBUTTON btn);
		std::shared_ptr<ItemManager>item_mgr(void);
	private:
		Game();
		~Game();
		Game(Game&)=delete;
		Game(Game&&) = delete;
		
	private:
		static Game* _game;//��̬��Ա����,���ʵ�����ȫ�ֱ���������������
		ID2D1Factory *_direct2dFactory = nullptr; /*��������*/
		std::shared_ptr<Avatar>_avatar;  //����ӵ��avatar
		ID2D1HwndRenderTarget * _renderTarget = nullptr;
		unsigned long _ticks = 0ul;
		std::shared_ptr<ItemManager>_item_manager;
		std::shared_ptr<ScoreMgr> _score_mgr;
		std::unordered_map<INPUTBUTTON, bool>_inputs;
	};


	//------------------------------------------
}


//------------------------------------------
#endif // !_GAME_H
