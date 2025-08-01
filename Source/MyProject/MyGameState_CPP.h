/*#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState_CPP.generated.h"

// 時間帯を表す列挙型 (ブループリントで作成したものをC++でも定義)
UENUM(BlueprintType)
enum class ETimeOfDay : uint8
{
    Morning,
    Daytime,
    Evening,
    Night
};

UCLASS()
class YOURPROJECT_API AMyGameState_CPP : public AGameStateBase
{
    GENERATED_BODY()

public:
    // コンストラクタ (初期値を設定する場所)
    AMyGameState_CPP();

    // Event Tickに相当する関数
    virtual void Tick(float DeltaTime) override;

protected:
    // ゲームが始まったときに呼ばれる関数
    virtual void BeginPlay() override;

public:
    // --- 時間関連の変数 ---

    // BlueprintReadOnly: ブループリントから読み取りのみ可能
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentDay;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentHour;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentMinute;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    ETimeOfDay CurrentTimeOfDay;

    // EditAnywhere: エディタの詳細パネルで編集可能
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    float TimeScale;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    bool bIsTimePaused;

    // --- 就寝イベント関連の変数 ---

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 LastCheckedSleepDay;

private:
    // C++内部でのみ使う変数
    float TimeAccumulator;

    // --- 関数 ---

    // UFUNCTION: ブループリントからも呼び出せるようにする (今回はC++内からのみ)
    void UpdateCurrentTimeOfDay();

    // 就寝イベント用の関数
    void TriggerSleepSequence();
    void WakeUpNewDay();

    // 環境更新用の関数 (中身は後で実装)
    UFUNCTION(BlueprintImplementableEvent, Category = "Time")
    void UpdateEnvironment();
}; */