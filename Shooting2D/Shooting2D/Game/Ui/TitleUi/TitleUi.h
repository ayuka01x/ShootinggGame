#pragma once
#include "System/Task/Task.h"

/// <summary>
/// タイトルUI
/// </summary>
class TitleUi : public Task {

public:

  /// <summary>
  /// コンストラクタ
  /// </summary>
  TitleUi();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~TitleUi();

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
  /// 破棄
  /// </summary>
  void DestroyTitleUi();

  /// <summary>
  /// ズームする
  /// </summary>
  void CheckZoom();

private:

  /// <summary>
  /// ロゴ
  /// </summary>
  int title_ui_logo_image_;

  /// <summary>
  /// ガイダンス
  /// </summary>
  int title_ui_guidance_image_;

  /// <summary>
  /// ロゴ横幅
  /// </summary>
  int title_logo_width_;

  /// <summary>
  /// ロゴ縦幅
  /// </summary>
  int title_logo_height_;

  /// <summary>
  /// ガイダンス縦幅
  /// </summary>
  int title_guidance_width_;

  /// <summary>
  /// ガイダンス横幅
  /// </summary>
  int title_guidance_height_;

  /// <summary>
  /// ロゴｘ座標
  /// </summary>
  int logo_x_;

  /// <summary>
  /// ロゴｙ座標
  /// </summary>
  int logo_y_;

  /// <summary>
  /// ガイダンスｘ座標
  /// </summary>
  int guidance_x_;

  /// <summary>
  /// ガイダンスｙ座標
  /// </summary>
  int guidance_y_;

  /// <summary>
  /// ガイダンスを表示するかどうかのフラグ
  /// </summary>
  bool show_guidance_;

  /// <summary>
  /// 経過時間を保持する変数
  /// </summary>
  float elapsed_time_;

  /// <summary>
  /// ズーム倍率
  /// </summary>
  float zoom_factor_;
 
};