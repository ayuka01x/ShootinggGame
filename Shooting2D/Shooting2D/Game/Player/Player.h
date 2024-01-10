#pragma once
#include "System/Task/Task.h"
#include "System/Task/TaskManager.h"
#include "Game/Level/BattleLevel.h"
#include "System/Task/BulletManager/BulletManager.h"
#include "Game/Effect/EffectBace/PlayerEffect/PlayerEffect.h"
#include "Game/GameInfo/AudioManager/AudioManager.h"
#include "Game/Item/ItemManager/ItemManager.h"
/// <summary>
/// プレイヤーのクラス
/// </summary>
class Player : public Task {

public:
  /// <summary>
  /// プレイヤーの動き種類
  /// </summary>
  enum class PlayerAnimeImageKind {
    /// <summary>
    /// 正面画像
    /// </summary>
    kFront,

    /// <summary>
    /// 左に傾いている画像
    /// </summary>
    kLeft,

    /// <summary>
    /// 右に傾いている画像
    /// </summary>
    kRight,

    /// <summary>
    /// 総数
    /// </summary>
    kMax,
  };
  /// <summary>
  /// コンストラクタ
  /// </summary>
  explicit Player();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~Player();

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// 毎フレームの更新処理
  /// </summary>
  /// <param name="delta_time">前回実行フレームからの経過時間（秒）</param>
  void Update(float delta_time) override;

  /// <summary>
  /// 毎フレームの描画処理
  /// </summary>
  void Render() override;

  /// <summary>
  /// プレイヤーレベルの管理するものを破棄
  /// </summary>
  void DestroyPlayer();

  /// <summary>
  /// Playerの動き
  /// </summary>
  /// <param name="animation"></param>
  /// <returns></returns>
  bool IsAnimationActive(PlayerAnimeImageKind animation);

  /// <summary>
  /// BulletManagerのセットアップ
  /// </summary>
  /// <param name="bullet_manager"></param>
  void SetBulletManager(BulletManager* bullet_manager);

  /// <summary>
  /// 円同士の当たり判定を行う関数
  /// </summary>
  /// <param name="x1"></param>
  /// <param name="y1"></param>
  /// <param name="x2"></param>
  /// <param name="y2"></param>
  /// <returns></returns>
  bool IsCircleCollision(float player_x, float player_y, float x, float y);

  /// <summary>
  /// セット
  /// </summary>
  /// <param name="enemy_manager"></param>
  void SetEnemyManager(EnemyManager* enemy_manager);

  /// <summary>
  /// EffectManagerセット
  /// </summary>
  /// <param name="effect_manager"></param>
  void SetEffectManager(EffectManager* effect_manager);

  /// <summary>
  /// ItemManagerセット
  /// </summary>
  /// <param name="item_manager"></param>
  void SetItemManager(ItemManager* item_manager);

  /// <summary>
  /// x座標
  /// </summary>
  int player_x_;

  /// <summary>
  /// y座標
  /// </summary>
  int player_y_;

  /// <summary>
  /// デフォルト
  /// </summary>
  int player_image_;

  /// <summary>
  /// プレイヤー画像の幅
  /// </summary>
  int player_width_;

  /// <summary>
  /// プレイヤー画像の高さ
  /// </summary>
  int player_height_;

  /// <summary>
  ///  現在のフレーム
  /// </summary>
  int current_frame_;

  /// <summary>
  /// イメージ画像
  /// </summary>
  int player_images_[static_cast <int>(PlayerAnimeImageKind::kMax)];

  /// <summary>
  /// BulletManagerのポインタ
  /// </summary>
  BulletManager* bullet_manager_;

  /// <summary>
  /// 正面に進む動き
  /// </summary>
  /// <returns></returns>
  bool IsFrontAnimation();

  /// <summary>
  /// 左に進む動き
  /// </summary>
  /// <returns></returns>
  bool IsLeftAnimation();

  /// <summary>
  /// 右に進む動き
  /// </summary>
  /// <returns></returns>
  bool IsRightAnimation();

  /// <summary>
  /// どの画像か
  /// </summary>
  /// <returns></returns>
  PlayerAnimeImageKind Animation();

  /// <summary>
  /// カウント
  /// </summary>
  int fire_counter_;

  /// <summary>
  /// EnemyManagerポインタ
  /// </summary>
  EnemyManager* enemy_manager_;

  /// <summary>
  /// Ｐｌａｙｅｒ生死
  /// </summary>
  bool player_death_;

  /// <summary>
  /// EffectManagerポインタ
  /// </summary>
  EffectManager* effect_manager_;

  /// <summary>
  /// エフェクト
  /// </summary>
  std::vector<EffectBase> effect_list_;

  /// <summary>
  /// オーディオマネージャーポインタ
  /// </summary>
  AudioManager* audio_manager_;

  /// <summary>
  /// アイテムマネージャーポインタ
  /// </summary>
  ItemManager* item_manager_;

  /// <summary>
  /// アイテム取得
  /// </summary>
  bool item_get_;

  /// <summary>
  /// 速くなる時間
  /// </summary>
  float item_speed_up_time_;

  /// <summary>
  /// プレイヤーの速さ
  /// </summary>
  float player_speed_;
};

