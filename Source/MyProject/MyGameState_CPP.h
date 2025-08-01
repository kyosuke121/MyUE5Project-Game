/*#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "MyGameState_CPP.generated.h"

// ���ԑт�\���񋓌^ (�u���[�v�����g�ō쐬�������̂�C++�ł���`)
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
    // �R���X�g���N�^ (�����l��ݒ肷��ꏊ)
    AMyGameState_CPP();

    // Event Tick�ɑ�������֐�
    virtual void Tick(float DeltaTime) override;

protected:
    // �Q�[�����n�܂����Ƃ��ɌĂ΂��֐�
    virtual void BeginPlay() override;

public:
    // --- ���Ԋ֘A�̕ϐ� ---

    // BlueprintReadOnly: �u���[�v�����g����ǂݎ��̂݉\
    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentDay;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentHour;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 CurrentMinute;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    ETimeOfDay CurrentTimeOfDay;

    // EditAnywhere: �G�f�B�^�̏ڍ׃p�l���ŕҏW�\
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time")
    float TimeScale;

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    bool bIsTimePaused;

    // --- �A�Q�C�x���g�֘A�̕ϐ� ---

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Time")
    int32 LastCheckedSleepDay;

private:
    // C++�����ł̂ݎg���ϐ�
    float TimeAccumulator;

    // --- �֐� ---

    // UFUNCTION: �u���[�v�����g������Ăяo����悤�ɂ��� (�����C++������̂�)
    void UpdateCurrentTimeOfDay();

    // �A�Q�C�x���g�p�̊֐�
    void TriggerSleepSequence();
    void WakeUpNewDay();

    // ���X�V�p�̊֐� (���g�͌�Ŏ���)
    UFUNCTION(BlueprintImplementableEvent, Category = "Time")
    void UpdateEnvironment();
}; */