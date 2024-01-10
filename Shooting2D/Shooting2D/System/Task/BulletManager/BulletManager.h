#pragma once
#include "System/Task/Task.h"
#include "Game/Enemy/EnemyManager/EnemyManager.h"
#include "Game/Enemy/EnemyBase/EnemyBase.h"
#include "Game/Effect/EffectManager/EffectManager.h"
#include "Game/Effect/EffectBace/EffectBase.h"
#include "Game/GameInfo/AudioManager/AudioManager.h"
/// <summary>
/// 前方宣言
/// </summary>
class Player;

/// <summary>
/// 前方宣言
/// </summary>
class BulletBase;


/// <summary>
/// クラス
/// </summary>
class BulletManager : public Task {
public:

  /// <summary>
  /// 弾の種類を定義
  /// </summary>
  enum class BulletKind {
    /// <summary>
    /// 通常弾
    /// </summary>
    kPlayerBullet,

    /// <summary>
    /// ボス弾
    /// </summary>
    kBossBullet,
  };

  /// <summary>
  /// コンストラクタ
  /// </summary>
  BulletManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~BulletManager();

  /// <summary>
  /// 必要な弾を必要な数だけ作成する
  /// </summary>
  void Initialize();

  /// <summary>
  /// 作成した弾を削除する
  /// </summary>
  void DestroyBullet();

  /// <summary>
  /// 作成した弾の更新
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time) override;

  /// <summary>
  /// 描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// 弾を発射する関数
  /// </summary>
  /// <param name="type">種類</param>
  /// <param name="x">x座標</param>
  /// <param name="y">y座標</param>
  void FireBullet(BulletKind type, float x, float y);

  /// <summary>
  /// 円同士の当たり判定を行う関数
  /// </summary>
  /// <param name="bullet"></param>
  /// <param name="enemy"></param>
  /// <returns></returns>
  bool IsCollision(BulletBase* bullet, EnemyBase* enemy);

  /// <summary>
  /// EnemyManager をセットする関数
  /// </summary>
  /// <param name="enemyManager"></param>
  void SetEnemyManager(EnemyManager* enemy_manager);

  /// <summary>
  /// セット
  /// </summary>
  /// <param name="effect_manager"></param>
  void SetEffecManager(EffectManager* effect_manager);

  /// <summary>
  /// 最大弾数
  /// </summary>
  static const int kMaxBullets = 30;

  /// <summary>
  /// 弾
  /// </summary>
  std::vector<BulletBase*> bullet_list_;

  /// <summary>
  /// EnemyBaseポインタ
  /// </summary>
  std::vector<EnemyBase*> enemy_lists_;

  /// <summary>
  /// エネミーマネージャポインタ
  /// </summary>
  EnemyManager* enemy_manager_;

  /// <summary>
  /// ボスダメージ
  /// </summary>
  int boss_count_;

  /// <summary>
  /// エフェクトマネージャー
  /// </summary>
  EffectManager* effect_manager_;

  /// <summary>
  /// エフェクトBaseポインタ
  /// </summary>
  std::vector<EffectBase*> effect_list_;

  /// <summary>
  /// オーディオマネージャーポインタ
  /// </summary>
  AudioManager* audio_manager_;

  /// <summary>
  /// ボス死亡
  /// </summary>
  bool boss_dead_;

  /// <summary>
  /// ミニボスカウント
  /// </summary>
  float miniboss_count_;

  /// <summary>
  /// ミニボス死亡
  /// </summary>
  bool miniboss_dead_;
};

