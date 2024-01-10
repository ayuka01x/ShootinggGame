#include "EnemyBase.h"

/// <summary>
/// コンストラクタ
/// </summary>
EnemyBase::EnemyBase() {

}

/// <summary>
/// デストラクタ
/// </summary>
EnemyBase::~EnemyBase() {

}

/// <summary>
/// 初期化
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
/// <param name="speed"></param>
/// <param name="image_path"></param>
void EnemyBase::Initialize(float x, float y, float speed, float time) {

}

/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void EnemyBase::Update(float delta_time) {

}

/// <summary>
/// 描画
/// </summary>
void EnemyBase::Render() {

}

/// <summary>
/// 敵の種類
/// </summary>
/// <returns></returns>
EnemyManager::EnemyKind EnemyBase::GetEnemyKind() {

  return enemy_kind_;
}

/// <summary>
/// 敵出現
/// </summary>
/// <returns></returns>
bool EnemyBase::IsEnemyFired() {
    return is_enemy_fired_;
}

/// <summary>
/// 敵が動く
/// </summary>
/// <param name="x"></param>
/// <param name="y"></param>
void EnemyBase::FireEnemy(float x, float y) {

}

/// <summary>
/// x座標取得
/// </summary>
/// <returns></returns>
float EnemyBase::GetX() {
  return 0;
}

/// <summary>
/// y座標取得
/// </summary>
/// <returns></returns>
float EnemyBase::GetY() {
  return 0;
}

/// <summary>
/// 横幅取得
/// </summary>
/// <returns></returns>
float EnemyBase::GetWidth() {
  return 0.0f;
}

/// <summary>
/// 発射されたかどうかを設定
/// </summary>
/// <param name="s_enemy_fired"></param>
void EnemyBase::SetEnemyFire(bool is_enemy_fired) {

}

/// <summary>
/// 外に出たかどうか設定
/// </summary>
/// <param name="is_tackle_enemy_out_of_screen"></param>
void EnemyBase::SetIsEnemyOutOfScreen(bool is_tackle_enemy_out_of_screen) {

}

/// <summary>
/// 弾があたったかどうか
/// </summary>
/// <param name="is_bullet_hit"></param>
void EnemyBase::SetBulletHit(bool is_bullet_hit) {
  
}

/// <summary>
/// 出現時間取得
/// </summary>
float EnemyBase::GetTime(){
  return 0;
}

/// <summary>
/// ボスが死んだかどうか
/// </summary>
/// <param name="boss_death"></param>
void EnemyBase::SetBossDeath(bool boss_death) {
  boss_death_ = boss_death;
}

/// <summary>
/// ミニボスが死んだかどうか
/// </summary>
/// <param name="miniboss_death"></param>
void EnemyBase::SetMiniBossDeath(bool miniboss_death) {
  miniboss_death_ = miniboss_death;
}






