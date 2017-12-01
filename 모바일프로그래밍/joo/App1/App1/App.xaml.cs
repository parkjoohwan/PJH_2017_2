using App1.view;

using Xamarin.Forms;

namespace App1
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();
            // 프로그램 실행시 가장 먼저 시작됨, 네비게이션페이지를 이용해서 startpage를 처음 화면으로 시작됨
            MainPage = new NavigationPage( new StartPage() );
        }

        protected override void OnStart()
        {
            // Handle when your app starts
        }

        protected override void OnSleep()
        {
            // Handle when your app sleeps
        }

        protected override void OnResume()
        {
            // Handle when your app resumes
        }
    }
}
