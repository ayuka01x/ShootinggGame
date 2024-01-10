#pragma once
#include "DxLib.h"

/// <summary>
/// フェードマネージャー
/// </summary>
class FadeManager {
public:

  /// <summary>
  /// 状態
  /// </summary>
  enum class FadeState {
    /// <summary>
    /// フェードなし
    /// </summary>
    kNone,

    /// <summary>
    /// フェードイン
    /// </summary>
    kFadingIn,

    /// <summary>
    /// フェードアウト
    /// </summary>
    kFadingOut,

    /// <summary>
    /// 完了
    /// </summary>
    kFinished
  };

  


  /// <summary>
  /// インスタンス取得
  /// </summary>
  /// <returns></returns>
  static FadeManager* GetInstance() {

    //生成されてないなら動的生成
    if (instance_ == nullptr) {
      instance_ = new FadeManager();
      instance_->Initialize();
    }
    return instance_;
  }

  /// <summary>
  /// 破棄
  /// </summary>
  static void Destroy() {
    //生成済みなら削除
    if (instance_ != nullptr) {
      delete instance_;
      instance_ = nullptr;
    }
  }

  /// <summary>
  /// 初期化
  /// </summary>
  void Initialize();

  /// <summary>
  /// フェードの状態を更新する関数
  /// </summary>
  /// <param name="delta_time"></param>
  void Update(float delta_time);


  /// <summary>
  /// フェードインを開始する関数
  /// </summary>
  /// <param name="duration"></param>
  void StartFadeIn(float fade_in_time);

  /// <summary>
  /// フェードアウトを開始する関数
  /// </summary>
  /// <param name="duration"></param>
  void StartFadeOut(float fade_out_time);

  /// <summary>
  /// 描画
  /// </summary>
  void Render();

  /// <summary>
  /// ロゴフェードアウト時間
  /// </summary>
  /// <param name="fade_out_time"></param>
  void StartLogoFade(float fade_out_time);

  /// <summary>
  /// ロゴフェードアウト
  /// </summary>
  void FadeOutLogo();

 

private:
  /// <summary>
  /// コンストラクタ
  /// </summary>
  FadeManager();

  /// <summary>
  /// デストラクタ
  /// </summary>
  virtual ~FadeManager();

  /// <summary>
  /// 画像ハンドル
  /// </summary>
  int fade_image_;

  /// <summary>
  /// 横幅
  /// </summary>
  int fade_width_;

  /// <summary>
  /// 立幅
  /// </summary>
  int fade_hight_;

  
  /// <summary>
  /// インスタンス
  /// </summary>
  static FadeManager* instance_;

  /// <summary>
  /// アルファ値
  /// </summary>
  int alpha_;

  /// <summary>
  /// フレーム総数
  /// </summary>
  float total_frames_;

  /// <summary>
  /// ロゴのアルファ値
  /// </summary>
  int logo_alpha_;

  /// <summary>
  /// ロゴ総フレーム
  /// </summary>
  float logo_total_frames_;
};