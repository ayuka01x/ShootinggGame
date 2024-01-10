#include "FadeManager.h"
#include "Game/GameInfo/GameInfo.h"
#include <iostream>

/// <summary>
/// 名前空間
/// </summary>
namespace {

  /// <summary>
  /// 完全不透明
  /// </summary>
  const int kFade = 255;

  /// <summary>
  /// フレーム数
  /// </summary>
  const int kFlame = 60;

  /// <summary>
  /// フェードイメージ画像
  /// </summary>
  const char* kFadeImage = "Assets/Image/Fade/FadeBlack.png";

  /// <summary>
  /// フェードを戻す
  /// </summary>
  const int kFadeBack = 264;
}

/// <summary>
/// 初期化
/// </summary>
FadeManager* FadeManager::instance_ = nullptr;



/// <summary>
/// コンストラクタ
/// </summary>
FadeManager::FadeManager()
  : fade_image_(0)
  , fade_width_(0)
  , fade_hight_(0)
  , alpha_(kFade)
  , logo_alpha_(kFade){
}

/// <summary>
/// デストラクタ
/// </summary>
FadeManager::~FadeManager() {
  
}

/// <summary>
/// 初期化
/// </summary>
void FadeManager::Initialize() {

  fade_image_= LoadGraph(kFadeImage);
  GetGraphSize(fade_image_, &fade_width_, &fade_hight_);
}

/// <summary>
/// フェードの状態を更新する
/// </summary>
/// <param name="delta_time"></param>
void FadeManager::Update(float delta_time) {
  
  alpha_ -= kFade / total_frames_;

  logo_alpha_ -= kFade / logo_total_frames_;
  if (alpha_ <= 0) {
    alpha_ = 0;
  }
  if (alpha_ >= kFade) {
    alpha_ = kFade;
  }

  
  if (logo_alpha_ <= 0) {
    logo_alpha_ = 0;
  }
  if (logo_alpha_ >= kFade) {
    logo_alpha_ = kFade;
  }
}



/// <summary>
/// フェードイン
/// </summary>
/// <param name="fade_in_time"></param>
void FadeManager::StartFadeIn(float fade_in_time) {

  //時間×フレーム数
  total_frames_ = fade_in_time * kFlame;
 logo_alpha_ = kFadeBack;
}



/// <summary>
/// フェードアウト
/// </summary>
/// <param name="fade_out_time"></param>
void FadeManager::StartFadeOut(float fade_out_time) {

  //時間×フレーム数
  total_frames_ = fade_out_time * -kFlame;

}

/// <summary>
/// 描画
/// </summary>
void FadeManager::Render() {
  SetDrawBlendMode(DX_BLENDMODE_ALPHA, alpha_);
  DrawExtendGraph(0, 0, kResolutionX, kResolutionY, fade_image_, TRUE);
  SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);

  
}

/// <summary>
/// ロゴフェードアウト時間
/// </summary>
/// <param name="fade_out_time"></param>
void FadeManager::StartLogoFade(float fade_out_time) {
  logo_total_frames_ = fade_out_time * kFlame;

}

/// <summary>
/// ロゴフェードアウト
/// </summary>
void FadeManager::FadeOutLogo() {
  SetDrawBlendMode(DX_BLENDMODE_ALPHA, logo_alpha_);
  
}
