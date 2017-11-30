using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace App1.Behavior
{
    public class ItemSelectedBehavior : Behavior<ListView>
    {
        protected override void OnAttachedTo(ListView bindable)
        {
            //컨트롤이 없어질 때 이벤트 핸들러 생성
            base.OnAttachedTo(bindable);
            bindable.ItemSelected += Bindable_ItemSelected;
        }

        protected override void OnDetachingFrom(ListView bindable)
        {
            //컨트롤이 없어질 때 이벤트 핸들러 제거
            base.OnDetachingFrom(bindable);
            bindable.ItemSelected -= Bindable_ItemSelected;
        }


        private void Bindable_ItemSelected(object sender, SelectedItemChangedEventArgs e)
        {
            
        }
    }
}
