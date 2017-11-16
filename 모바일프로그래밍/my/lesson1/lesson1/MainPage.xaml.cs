using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace lesson1
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
        }
        private void Button_Clicked1(object sender, EventArgs e)
        {
            Navigation.PushAsync(new Page1());
            // 비동기 프로그램을 하면서 오류가 많이남
            // 쓰레드 거의 안씀
        }
        private void Button_Clicked2(object sender, EventArgs e)
        {
            Navigation.PushAsync(new Page2());
            // 비동기 프로그램을 하면서 오류가 많이남
            // 쓰레드 거의 안씀
        }
        private void Button_Clicked3(object sender, EventArgs e)
        {
            Navigation.PushAsync(new Page3());
            // 비동기 프로그램을 하면서 오류가 많이남
            // 쓰레드 거의 안씀
        }

    }
}


// 비동기 함수의 리턴값이 언제 올지 모르는 경우 비동기적이라고 한다.
// 신호가 오기전까지 프로세스가 대기하지않음 = 비동기
// iPhone ,,