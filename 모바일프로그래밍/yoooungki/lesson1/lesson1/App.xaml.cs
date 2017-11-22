using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

using Xamarin.Forms;

namespace lesson1
{
    public partial class App : Application
    {
        public App()
        {
            InitializeComponent();

            MasterDetailPage p = new MasterDetailPage();
            p.Master = new Master() { Title = "page 1" };
            p.Detail = new NavigationPage(new lesson1.MainPage());

            MainPage = new NavigationPage(new lesson1.MainPage()) { Title = "Detail" }; 
            // 네이게이션 페이지의 첫 페이지를 메인 페이지로 하겠다.
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

// 클래스 정의 = 빵틀 만듬
// 인스턴스 생성 = 빵을 만듬 = 객체