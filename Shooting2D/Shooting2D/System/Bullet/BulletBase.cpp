#include "BulletBase.h"
#include "DxLib.h"
#include <string>
#include <vector>


/// <summary>
/// コンストラクタ
/// </summary>
BulletBase::BulletBase()
  : is_fired_(false){
  
}

/// <summary>
/// デストラクタ
/// </summary>
BulletBase::~BulletBase() {

  
}

/// <summary>
/// 弾の初期化
/// </summary>
/// <param name="x">位置</param>
/// <param name="y">位置</param>
/// <param name="speed">速さ</param>
/// <param name="image_path">画像</param>
void BulletBase::Initialize(float x, float y, float speed) {
 
}

/// <summary>
/// 弾の更新処理
/// </summary>
/// <param name="delta_time"></param>
void BulletBase::Update(float delta_time) {
  
}

/// <summary>
/// 弾の描画処理
/// </summary>
void BulletBase::Render() {


}

/// <summary>
/// 発射済みかどうかを返す関数
/// </summary>
/// <returns></returns>
bool BulletBase::IsFired(){

  return is_fired_;
}

/// <summary>
/// 種類取得
/// </summary>
/// <returns></returns>
BulletManager::BulletKind BulletBase::GetBulletKind() {
  return bullet_kind_;
}

/// <summary>
/// 弾を発射する処理
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BulletBase::FireBullet(float x, float y) {
  
}

/// <summary>
/// 弾が外に出たかどうか
/// </summary>
/// <returns></returns>
bool BulletBase::IsOutOfScreen() {
  return 0;
}

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float BulletBase::GetX() {
  return 0;
}

/// <summary>
/// y座標取得
/// </summary>
/// <returns></returns>
float BulletBase::GetY() {
  return 0;
}

/// <summary>
/// 横幅取得
/// </summary>
/// <returns></returns>
float BulletBase::GetWidth() {
  return 0.0f;
}

/// <summary>
/// 弾が発射されたかどうかを設定
/// </summary>
/// <param name="fired"></param>
void BulletBase::SetFired(bool fired) {
}

/// <summary>
/// 外に出たかどうか
/// </summary>
/// <param name="out_of_screen"></param>
void BulletBase::SetIsOutOfScreen(bool out_of_screen)
{
}

/// <summary>
/// 弾の座標を設定する関数
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void BulletBase::SetPosition(float x, float y) {
}