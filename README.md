# DX11Practice3D - RPG 게임 개발 계획  


# 1. 엔진완성(콜리더, 리지드바디가 없는 상태) (이는 유니티 엔진처럼 필요한 컴포넌트를 추가하도록한다.)
# 2. 기본 에디터 프레임워크 구성 (맵툴, 애니메이터, 계층구조 뷰어 등등..) + 씬관리 및 오브젝트 관리 개선 작업
# 3. 세부 시스템 로직 설계.  
  3-1: 맵툴의 개발(지형과 오브젝트 배치와 콜리더를 함께 설정 및 해제할 수 있는 환경) .
  3-2: 맵툴의 결과물을 저장하고 이를 클라이언트에서 불러올 수 있는 로더 개발.
  3-3: imgui로 on off 할 수 있는 충돌 라인 디버그 모드 개발.
  3-4: 사용자 키 입력에 맞는 조작(이동과 스킬) 그리고 기본 물리(충돌과 중력) 그리고 스킬사용에 대한 기본 테스트 환경 구축.
  3-5: 충돌 로직에 의한 데미지 이펙트나 여러 요소 테스트.
  3-6: FSM을 활용한 적 AI 개발.
  3-7: 사용자 UI개발.  
  
# 4. 전투 시스템 테스트 
(사용자 이동, 스킬 사용, 이펙트, 씬(map)간 이동, 전투 시스템 로직 작동여부, )
(파밍 시스템 작동 여부, 인벤토리 시스템 작동 여부<인벤토리는 추후 추가하도록 한다.>)
