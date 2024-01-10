#pragma once
#include "Game/Level/LevelBase.h"
#include "Game/Player/Player.h"
#include "System/Task/BulletManager/BulletManager.h"
#include "Game/Ui/BattleUi/BattleUi.h"
#include "Game/Ui/SideUi/SideUi.h"
#include "Game/FadeManager/FadeManager.h"
#include "Game/Enemy/EnemyManager/EnemyManager.h"
#include "Game/Enemy/EnemyBase/BossEnemy/BossEnemy.h"
#include "Game/Effect/EffectManager/EffectManager.h"
#include "Game/GameInfo/AudioManager/AudioManager.h"
#include"Game/Item/ItemManager/ItemManager.h"
#include <string>
/// <summary>
/// バトル画面のレベル
/// </summary>
class BattleLevel : public LevelBase {
private:


  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  enum class BattleLevelState {

    /// <summary>
    /// 処理なし
    /// </summary>
    kNone,

    /// <summary>
    /// 通常処理
    /// </summary>
    kPlay,
  };

  /// <summary>
  /// 画像の総数
  /// </summary>
  enum class BattleScrean {

    /// <summary>
    /// １枚目
    /// </summary>
    kImageScrollOne,

    /// <summary>
    /// ２枚目
    /// </summary>
    kImageScrollTwo,

    /// <summary>
    /// 3枚目
    /// </summary>
    kImageScrollThree,

    /// <summary>
    /// 総数
    /// </summary>
    kMax,
  };

public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  explicit BattleLevel();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~BattleLevel();

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
  /// レベルの開始処理
  /// </summary>
  void BeginLevel() override;

  /// <summary>
  /// バトルレベルの管理するものをタスクマネージャーから解放する
  /// </summary>
  void ReleaseLevel() override;

  /// <summary>
  /// バトルレベルの管理するものを破棄
  /// </summary>
  void DestroyLevel() override;

  /// <summary>
  /// ボスバトル
  /// </summary>
  void BossBattle();

  /// <summary>
  /// タックルエネミーバトル
  /// </summary>
  void TackleEnemyBattle();

  /// <summary>
  /// ミニボスバトル
  /// </summary>
  void MiniBossBattle();

  /// <summary>
  /// アイテム発射
  /// </summary>
  void ItemFire();
private:

  /// <summary>
  /// バトルレベルの状態
  /// </summary>
  BattleLevelState battle_level_state_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int battle_bg_handle_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int bg_handle_one_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int bg_handle_two_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int bg_handle_three_;

  /// <summary>
  /// 現在の経過時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// Playerインスタンス
  /// </summary>
  Player* player_;

  /// <summary>
  /// スクロールされる画像
  /// </summary>
  int battle_scroll_handles_[static_cast <int>(BattleScrean::kMax)];

  /// <summary>
  /// BulletManagerのポインタ
  /// </summary>
  BulletManager* bullet_manager_;

  /// <summary>
  /// BattleUiのポインタ
  /// </summary>
  BattleUi* battle_ui_;

  /// <summary>
  /// SideUiのポインタ
  /// </summary>
  SideUi* side_ui_;

  /// <summary>
  /// EnemyManagerのポインタ
  /// </summary>
  EnemyManager* enemy_manager_;

  /// <summary>
  /// フェードアウトかどうか
  /// </summary>
  bool fade_out_;

  /// <summary>
  /// 敵発射時間
  /// </summary>
  float enemy_elapsed_time_;

  /// <summary>
  /// ボス発射時間
  /// </summary>
  float boss_elapsed_time_;

  /// <summary>
  /// ボスカウント
  /// </summary>
  int boss_count_;

  /// <summary>
  /// エフェクトマネージャー
  /// </summary>
  EffectManager* effect_manager_;

  /// <summary>
  /// オーディオマネージャー
  /// </summary>
  AudioManager* audio_manager_;

  /// <summary>
  /// 画面切り替え時間
  /// </summary>
  float finish_elapsed_time_;

  /// <summary>
  /// バトルUI出たかどうか
  /// </summary>
  bool battle_ui_fire_;

  /// <summary>
  /// アイテムマネージャーポインタ
  /// </summary>
  ItemManager* item_manager_;

  /// <summary>
  /// アイテム出現時間
  /// </summary>
  float item_time_;

  /// <summary>
  /// アイテムx座標
  /// </summary>
  int item_x_;

  /// <summary>
  /// ボスバトルまでのラグ
  /// </summary>
  float boss_battle_time_;
};