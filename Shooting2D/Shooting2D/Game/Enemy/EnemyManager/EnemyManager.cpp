#include "EnemyManager.h"
#include "Game/Enemy/EnemyBase/TackleEnemy/TackleEnemy.h"
#include "Game/Enemy/EnemyBase/BossEnemy/BossEnemy.h"
#include "Game/Enemy/EnemyBase/BossEnemy/MiniBoss.h"
#include <iostream>
#include <fstream>
#include <sstream>

/// <summary>
/// 名前空間
/// </summary>
namespace {
  /// <summary>
  /// 最初の敵の初期X位置
  /// </summary>
  const float kStartX = 200.0f;

  /// <summary>
  /// 最初の敵の初期Y位置
  /// </summary>
  const float kStartY = 0.0f;

  /// <summary>
  /// 敵と敵の間の横のスペース
  /// </summary>
  const float kSpacingX = 100.0f;

  /// <summary>
  /// 敵の位置終わり
  /// </summary>
  const float kFinishX = 1000.0f;

  /// <summary>
  /// タックルエネミー
  /// </summary>
  const char* kTackleEnemy = "Assets/Image/Battle/Enemy/TackleEnemy.png";

  /// <summary>
  /// 敵の横列
  /// </summary>
  const int kEnemyX = 15;

  /// <summary>
  /// 敵の数
  /// </summary>
  const int kEnemyCount = 1;

  /// <summary>
  /// 敵総数
  /// </summary>
  const int kMaxEnemy = 16;

  /// <summary>
  /// ボス初期位置
  /// </summary>
  const int kBossPlaceX = 1500;

  /// <summary>
  /// ボス初期位置
  /// </summary>
  const int kBossPlaceY = -100;

  /// <summary>
  /// タックルエネミー
  /// </summary>
  const int kAllTackleEnemy = 60;

}

/// <summary>
/// コンストラクタ
/// </summary>
EnemyManager::EnemyManager()
  : start_x_(0)
  , start_y_(0)
  , spacing_x_(0)
  , spacing_y_(0)
  , boss_x_(0)
  , boss_y_(0) {

}

/// <summary>
/// デストラクタ
/// </summary>
EnemyManager::~EnemyManager() {
}

/// <summary>
/// 初期化
/// </summary>
void EnemyManager::Initialize() {
  LoadEnemyPlacement("Assets/Stage/EnemyPlacement.csv");
  for (int i = 0; i < kAllTackleEnemy; ++i) {
    const auto& enemy_placement = enemy_placement_data_[i];

    switch (enemy_placement.type) {
    case EnemyKind::kTackleEnemy: {

      // TackleEnemy クラスのインスタンスを生成
      TackleEnemy* tackle_enemy = new TackleEnemy();
      // TackleEnemy の初期化
      tackle_enemy->Initialize(enemy_placement.x, enemy_placement.y, kStartX, enemy_placement.in_time);
      // enemy_list_ に TackleEnemy を追加
      enemy_list_.push_back(tackle_enemy);
    }
                                break;

    case EnemyKind::kBossEnemy: {
      // BossEnemy クラスのインスタンスを生成
      BossEnemy* boss_enemy = new BossEnemy();
      // BossEnemy の初期化(必要に応じて引数を変更）
      boss_enemy->Initialize(enemy_placement.x, enemy_placement.y, kSpacingX, enemy_placement.in_time);
      // enemy_list_ に BossEnemy を追加
      enemy_list_.push_back(boss_enemy);
    }
                              break;
    case EnemyKind::kMiniBossEnemy: {

      MiniBossEnemy* miniboss_enemy = new MiniBossEnemy();

      miniboss_enemy->Initialize(enemy_placement.x, enemy_placement.y, kSpacingX, enemy_placement.in_time);

      enemy_list_.push_back(miniboss_enemy);
    }
                                  break;
    }
    
  }

  
}

/// <summary>
/// 破棄
/// </summary>
void EnemyManager::DestroyEnemy() {
  for (auto it = enemy_list_.begin(); it != enemy_list_.end(); ++it) {
    delete (*it);
  }

  // ベクタをクリア
  enemy_list_.clear();
}


/// <summary>
/// 更新
/// </summary>
/// <param name="delta_time"></param>
void EnemyManager::Update(float delta_time) {
  elapsed_time_ += delta_time;
  for (auto it = enemy_list_.begin(); it != enemy_list_.end(); ++it) {
    (*it)->Update(delta_time);
  }
}

/// <summary>
/// 描画処理
/// </summary>
void EnemyManager::Render() {
  for (auto it = enemy_list_.begin(); it != enemy_list_.end(); ++it) {
    (*it)->Render();
  }
}

/// <summary>
/// エネミー発射
/// </summary>
/// <param name="kind"></param>
/// <param name="x"></param>
/// <param name="y"></param>
void EnemyManager::EnemyFire(EnemyKind kind) {

  for (std::vector<EnemyBase*>::iterator itr = enemy_list_.begin(); itr != enemy_list_.end(); ++itr) {
    if ((*itr)->GetEnemyKind() != kind) {
     
      continue;
    }

    if ((*itr)->IsEnemyFired()) {
      continue;
    }

    if (elapsed_time_ >= (*itr)->GetTime()) {
      (*itr)->FireEnemy((*itr)->GetX(), (*itr)->GetY());
      break;
    }
  }
}

/// <summary>
/// ボスX座標取得
/// </summary>
/// <returns></returns>
float EnemyManager::GetBossX(){
  for (auto it = enemy_list_.begin(); it != enemy_list_.end(); ++it) {
    
    float x = (*it)->GetX();
    EnemyManager::EnemyKind kind = (*it)->GetEnemyKind();

    if (kind == EnemyManager::EnemyKind::kBossEnemy) {
      return x;
    }
  }

  

}

/// <summary>
/// 敵情報
/// </summary>
/// <param name="filename"></param>
void EnemyManager::LoadEnemyPlacement(const std::string filename) {
  std::ifstream stream(filename, std::ios::in);
  if (!stream) {
    std::cout << "ファイルが開けません" << std::endl;
    
  }
  std::string skipLine;
  getline(stream, skipLine);
  std::string line;

  while (getline(stream, line)) {
    std::istringstream iss(line);
    EnemyPlacement enemy;

    // カンマで分割して情報を構造体に格納
    std::string enemyType;
    getline(iss, enemyType, ',');
    if (enemyType == "kTackleEnemy") {
      enemy.type = EnemyKind::kTackleEnemy;
    }
    else if (enemyType == "kBossEnemy") {
      enemy.type = EnemyKind::kBossEnemy;
    }
    else if (enemyType == "kMiniBossEnemy") {
      enemy.type = EnemyKind::kMiniBossEnemy;
    }
    
    iss >> enemy.in_time;
    iss.ignore();
    iss >> enemy.x;
    iss.ignore(); 
    iss >> enemy.y;

   
    enemy_placement_data_.push_back(enemy);

    std::cout << "Enemy Type: " << enemyType
      << ", In Time: " << enemy.in_time
      << ", X: " << enemy.x
      << ", Y: " << enemy.y << std::endl;
  }
  //ファイルを閉じる
  stream.close();
  std::cout << "ファイルを読み込みました" << std::endl;
  
}

