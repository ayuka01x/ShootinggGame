#include "BulletManager.h"
#include "DxLib.h"
#include "System/Bullet/PlayerBullet.h"
#include "System/Input/InputManager.h"
#include "System/Bullet/BossBullet/BossBullet.h"
#include <iostream>

/// <summary>
/// 前方宣言
/// </summary>
class Player;

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// 弾の初期位置
  /// </summary>
  const int kBulletPositionX = -50;

  /// <summary>
  /// 衝突の距離
  /// </summary>
  const int kRadius = 1000;

  /// <summary>
  /// ボス衝突の距離
  /// </summary>
  const int kBossRadius = 1200;

  /// <summary>
  /// 弾総数
  /// </summary>
  const int kAllBullet = 60;

  /// <summary>
  /// ボスライフ
  /// </summary>
  const int kBossCount = 50;

  /// <summary>
  /// ボス弾ｘ座標
  /// </summary>
  const int kBossBulletX = 720;

  /// <summary>
  /// ミニボスライフ
  /// </summary>
  const int kMiniBossCount = 10;
}
/// <summary>
/// コンストラクタ
/// </summary>
BulletManager::BulletManager()
  : enemy_manager_(nullptr)
  , boss_count_(0)
  , boss_dead_(false)
  , miniboss_dead_(false) {


}

/// <summary>
/// デストラクタ
/// </summary>
BulletManager::~BulletManager() {

}

/// <summary>
/// 必要な弾を必要な数だけ作成する
/// </summary>
void BulletManager::Initialize() {
  for (int i = 0; i < kMaxBullets; ++i) {
    // PlayerBulletクラスのインスタンスを作成
    PlayerBullet* bullet = new PlayerBullet();

    bullet->Initialize(kBulletPositionX, 0, 0);

    // リストに追加
    bullet_list_.push_back(bullet);

  }
  for (int i = 0; i < kMaxBullets; ++i) {
    BossBullet* boss_bullet = new BossBullet();
    boss_bullet->Initialize(kBossCount, kBossBulletX, 0);
    bullet_list_.push_back(boss_bullet);
  }

  audio_manager_ = new AudioManager;
  audio_manager_->LoadSe();
}

/// <summary>
/// プレイヤー弾の更新処理
/// </summary>
/// <param name="delta_time"></param>
void BulletManager::Update(float delta_time) {
  // バレットの更新処理
  for (int i = 0; i < kAllBullet; ++i) {
    if (bullet_list_[i] != nullptr && bullet_list_[i]->IsFired()) {
      bullet_list_[i]->Update(delta_time);
    }
  }

  // EnemyManagerがnullptrの際は、この先の処理をしない。
  if (enemy_manager_ == nullptr) {
    return;
  }

  for (int i = 0; i < kAllBullet; ++i) {
    for (EnemyBase* enemy : enemy_manager_->enemy_list_) {
      if (bullet_list_[i] != nullptr && enemy != nullptr) {
        if (IsCollision(bullet_list_[i], enemy) && bullet_list_[i]->IsFired()) {

          if (bullet_list_[i]->GetBulletKind() == BulletManager::BulletKind::kPlayerBullet) {
            // 衝突した場合の処理
           


            if (enemy->GetEnemyKind() == EnemyManager::EnemyKind::kTackleEnemy) {
              effect_manager_->EffectFire(EffectManager::EffectKind::kEnemyEffect, enemy->GetX(), enemy->GetY());
              bullet_list_[i]->SetFired(false);
              bullet_list_[i]->SetIsOutOfScreen(true);
              if (enemy->GetY() != kBulletPositionX) {
                audio_manager_->PlaySe(AudioManager::EffectKind::kTackleEnemyExplotionEffect);
                enemy->SetEnemyFire(false);
                enemy->SetIsEnemyOutOfScreen(true);
              }



            }

            // プレイヤーの弾がボスに当たった場合の処理
            if (enemy->GetEnemyKind() == EnemyManager::EnemyKind::kBossEnemy) {
              boss_count_++;
              bullet_list_[i]->SetFired(false);
              bullet_list_[i]->SetIsOutOfScreen(true);
              audio_manager_->PlaySe(AudioManager::EffectKind::kBossEnemyDamageEffect);
              enemy->SetBulletHit(false);
              if (boss_count_ >= kBossCount) {

                // ボスを倒した
                effect_manager_->EffectFire(EffectManager::EffectKind::kBossEffect, enemy->GetX(), enemy->GetY());
                audio_manager_->PlaySe(AudioManager::EffectKind::kBossEXplotionEffect);
                enemy->SetEnemyFire(false);
                enemy->SetIsEnemyOutOfScreen(true);
                enemy->SetBossDeath(true);

                boss_dead_ = true;
              }
            }
            if (enemy->GetEnemyKind() == EnemyManager::EnemyKind::kMiniBossEnemy) {
              miniboss_count_++;
              if (!miniboss_dead_) {
                bullet_list_[i]->SetFired(false);
                bullet_list_[i]->SetIsOutOfScreen(true);
                audio_manager_->PlaySe(AudioManager::EffectKind::kBossEnemyDamageEffect);
                enemy->SetBulletHit(false);
                if (miniboss_count_ >= kMiniBossCount) {
                  effect_manager_->EffectFire(EffectManager::EffectKind::kBossEffect, enemy->GetX(), enemy->GetY());
                  audio_manager_->PlaySe(AudioManager::EffectKind::kBossEXplotionEffect);

                  enemy->SetMiniBossDeath(true);

                  miniboss_dead_ = true;
                }
              }
              
            }

          }


        }
      }

    }
    if (boss_count_ >= kBossCount) {
      if (bullet_list_[i]->GetBulletKind() == BulletManager::BulletKind::kBossBullet) {
        bullet_list_[i]->SetFired(false);
        bullet_list_[i]->SetIsOutOfScreen(true);
      }
      

    }
  }

}

/// <summary>
/// 描画処理
/// </summary>
void BulletManager::Render() {
  for (int i = 0; i < kAllBullet; ++i) {
    if (bullet_list_[i] != nullptr) {
      bullet_list_[i]->Render();
    }
  }
}

/// <summary>
/// 作成した弾を削除する
/// </summary>
void BulletManager::DestroyBullet() {
  for (int i = 0; i < kAllBullet; ++i) {
    if (bullet_list_[i] != nullptr) {
      delete bullet_list_[i];
      bullet_list_[i] = nullptr;
    }
  }
  audio_manager_->DeleteSe();
  delete audio_manager_;
  audio_manager_ = nullptr;

  bullet_list_.clear();
}

/// <summary>
/// バレットの発射
/// </summary>
/// <param name="type">種類</param>
/// <param name="x">x座標</param>
/// <param name="y">y座標</param>
void BulletManager::FireBullet(BulletKind type, float x, float y) {

  //バレットベースのポインタ型
  for (std::vector<BulletBase*>::iterator itr = bullet_list_.begin(); itr != bullet_list_.end(); ++itr) {

    //違うバレット種類なら次へ
    if ((*itr)->GetBulletKind() != type) {

      //ループの最初の処理から再び実行。英語と意味同じ。
      continue;
    }

    //発射済みなら次へ
    if ((*itr)->IsFired()) {

      continue;
    }

    //バレット発射
    (*itr)->FireBullet(x, y);

    //発射したので抜ける
    break;
  }
}

/// <summary>
/// 円同士の当たり判定を行う関数
/// </summary>
/// <param name="bullet"></param>
/// <param name="enemy"></param>
/// <returns></returns>
bool BulletManager::IsCollision(BulletBase* bullet, EnemyBase* enemy) {
  float bullet_x_ = bullet->GetX();
  float bullet_y_ = bullet->GetY();



  // 2点間の距離を計算
  if (enemy->GetEnemyKind() == EnemyManager::EnemyKind::kTackleEnemy) {
    float enemy_x_ = enemy->GetX();
    float enemy_y_ = enemy->GetY();
    float distance_x_ = bullet_x_ - enemy_x_;
    float distance_y_ = bullet_y_ - enemy_y_;
    float distance_ = distance_x_ * distance_x_ + distance_y_ * distance_y_;

    return distance_ <= kRadius;
  }


  if (enemy->GetEnemyKind() == EnemyManager::EnemyKind::kBossEnemy || enemy->GetEnemyKind() == EnemyManager::EnemyKind::kMiniBossEnemy) {
    float enemy_x_ = enemy->GetX();
    float enemy_y_ = enemy->GetY();
    float distance_x_ = bullet_x_ - enemy_x_ - kBossCount;
    float distance_y_ = bullet_y_ - enemy_y_;
    float distance_ = distance_x_ * distance_x_ + distance_y_ * distance_y_;

    return distance_ <= kBossRadius;
  }

}

/// <summary>
/// EnemyManagerをセットする関数
/// </summary>
/// <param name="enemy_manager"></param>
void BulletManager::SetEnemyManager(EnemyManager* enemy_manager) {
  enemy_manager_ = enemy_manager;
}

/// <summary>
/// 
/// </summary>
/// <param name="effect_manager"></param>
void BulletManager::SetEffecManager(EffectManager* effect_manager) {
  effect_manager_ = effect_manager;
}





