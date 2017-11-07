// Splash Screen 사용 모듈
function  show_SplashScreen() {
	// bIsDisplayed  0 이면 처음 출력, bIsDisplayed 1 이면 이미 출력 
	 var bIsDisplayed = sessionStorage.getItem("bIsDisplayed");
	 if (bIsDisplayed == 0) { show_SplashImage(); }
}
function show_SplashImage() {
	// 시작 화면 표시
	navigator.splashscreen.show();
	
	// 이미 출력했으므로 bIsDisplayed 변수에 1을 설정하여 다음에 표시 안함
	sessionStorage.setItem("bIsDisplayed", "1");
}
