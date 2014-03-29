#pragma once
#include "../Type.h"

NS_MPF
NS_VSL

class RenderCoreProvider;

enum class RenderCoreProviders
{
	//GDI
	GDI
};

//ϵͳ����
class NativeWindow : public Object, public std::enable_shared_from_this<NativeWindow>
{
public:
	//���� NativeWindow ����ʵ��
	MPF_API NativeWindow();
	MPF_API ~NativeWindow();

	//����
	MPF_API void Create();
	//��ʾ
	MPF_API void Show() const;

	//��ȡ����
	MPF_API std::shared_ptr<String> GetTitle() const;
	//���ñ���
	MPF_API void SetTitle(std::shared_ptr<String> title);

	//��ȡ����
	MPF_API uint GetWidth() const;
	//���ÿ���
	MPF_API void SetWidth(uint width);

	//��ȡ�߶�
	MPF_API uint GetHeight() const;
	//���ø߶�
	MPF_API void SetHeight(uint height);

	//��ȡ�ͻ�������
	MPF_API uint GetClientWidth() const;

	//��ȡ�ͻ����߶�
	MPF_API uint GetClientHeight() const;

	//��ȡ������ʶ��
	MPF_API handle_t GetNativeHandle() const;

	//���� RenderCoreProvider
	MPF_API std::shared_ptr<RenderCoreProvider> CreateRenderCoreProvider(RenderCoreProviders provider);

	//��ȡ����
	MPF_API DECLARE_GETTYPE(NativeWindow)
protected:
	//���ڹ���
	MPF_API long _w64 _stdcall WindowProc(handle_t hWnd, uint msg, uint _w64 wParam, long _w64 lParam);
private:
	static void CreateWindowClass();
	static long _w64 _stdcall WindowProcWrapper(handle_t hWnd, uint msg, uint _w64 wParam, long _w64 lParam);
private:
	handle_t handle = nullptr;
	DECLARE_TYPE(NativeWindow)
};

NS_ED
NS_ED