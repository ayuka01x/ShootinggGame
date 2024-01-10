#pragma once
#include "Game/Level/LevelBase.h"
#include "Game/Ui/TitleUi/TitleUi.h"
#include "Game/Ui/SideUi/SideUi.h"
#include "Game/FadeManager/FadeManager.h"
#include "Game/GameInfo/AudioManager/AudioManager.h"
/// <summary>
/// タイトル画面のレベル
/// </summary>
class TitleLevel : public LevelBase {

public:

  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  enum class TitleLevelState {

    /// <summary>
    /// 処理なし
    /// </summary>
    kNone,

    /// <summary>
    /// 通常処理
    /// </summary>
    kPlay,
  };

public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  explicit TitleLevel();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~TitleLevel();

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
  /// タイトルレベルの管理するものをタスクマネージャーから解放する
  /// </summary>
  void ReleaseLevel() override;

  /// <summary>
  /// タイトルレベルの管理するものを破棄
  /// </summary>
  void DestroyLevel() override;

private:

  /// <summary>
  /// タイトルレベルの状態
  /// </summary>
  TitleLevelState title_level_state_;

  /// <summary>
  /// 背景画像
  /// </summary>
  int title_bg_handle_;

  /// <summary>
  /// 現在の経過時間
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// ポインタ
  /// </summary>
  TitleUi* title_ui_;

  /// <summary>
  /// タイトルタイマー
  /// </summary>
  int  title_timer_;

  /// <summary>
  /// SideUiポインタ
  /// </summary>
  SideUi* side_ui_;

  /// <summary>
  /// ｚを押したかどうか
  /// </summary>
  bool z_pressed_;

  /// <summary>
  /// フェードに使う
  /// </summary>
  int fade_;

  /// <summary>
  /// フェードアウトするかどうか
  /// </summary>
  bool fade_out_;

  /// <summary>
  /// オーディオマネージャーポインタ
  /// </summary>
  AudioManager* audio_manager_;
};