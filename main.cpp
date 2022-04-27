#include <Novice.h>
#include<math.h>

const char kWindowTitle[] = "LE2B_17_ニイダ_シュウト:AffinMtrix";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	float box[4][3] = {
		{ 100.0f, 100.0f,1.0f},
		{ 100.0f, 200.0f,1.0f},
		{ 200.0f, 200.0f,1.0f},
		{ 200.0f, 100.0f,1.0f},
	};

	float boxMoved[4][3];

	float affinMove[3][3] = {
		{1,0,10},
		{0,1,0},
		{0,0,1},
	};


	// affin行列をつかって、boxをboxMovedに変換
	
		boxMoved[0][0] = affinMove[0][0] * box[0][0] + affinMove[0][1] * box[0][1] + affinMove[0][2] * box[0][2];
		boxMoved[0][1] = affinMove[1][0] * box[0][0] + affinMove[1][1] * box[0][1] + affinMove[1][2] * box[0][2];
		boxMoved[0][2] = affinMove[2][0] * box[0][0] + affinMove[2][1] * box[0][1] + affinMove[2][2] * box[0][2];
		boxMoved[1][0] = affinMove[0][0] * box[1][0] + affinMove[0][1] * box[1][1] + affinMove[0][2] * box[1][2];
		boxMoved[1][1] = affinMove[1][0] * box[1][0] + affinMove[1][1] * box[1][1] + affinMove[1][2] * box[1][2];
		boxMoved[1][2] = affinMove[2][0] * box[1][0] + affinMove[2][1] * box[1][1] + affinMove[2][2] * box[1][2];
		boxMoved[2][0] = affinMove[0][0] * box[2][0] + affinMove[0][1] * box[2][1] + affinMove[0][2] * box[2][2];
		boxMoved[2][1] = affinMove[1][0] * box[2][0] + affinMove[1][1] * box[2][1] + affinMove[1][2] * box[2][2];
		boxMoved[2][2] = affinMove[2][0] * box[2][0] + affinMove[2][1] * box[2][1] + affinMove[2][2] * box[2][2];
		boxMoved[3][0] = affinMove[0][0] * box[3][0] + affinMove[0][1] * box[3][1] + affinMove[0][2] * box[3][2];
		boxMoved[3][1] = affinMove[1][0] * box[3][0] + affinMove[1][1] * box[3][1] + affinMove[1][2] * box[3][2];
		boxMoved[3][2] = affinMove[2][0] * box[3][0] + affinMove[2][1] * box[3][1] + affinMove[2][2] * box[3][2];
	
	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///
		
		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		
		for (int i = 0; i < 4; i++)
		{
			//1行で4辺全てを描画
			Novice::DrawLine(box[i][0], box[i][1], box[(i + 1) % 4][0], box[(i + 1) % 4][1], RED);
			Novice::DrawLine(boxMoved[i][0], boxMoved[i][1], boxMoved[(i + 1) % 4][0], boxMoved[(i + 1) % 4][1], GREEN);

		}
		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
