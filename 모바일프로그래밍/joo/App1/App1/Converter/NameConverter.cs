using System;
using System.Collections.Generic;
using System.Globalization;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using Xamarin.Forms;

namespace App1.Converter
{
    public class NameConverter : IValueConverter
    {
        // 뷰 모델에서 뷰로 갈 때 호출되는 함수
        public object Convert(object value, Type targetType, object parameter, CultureInfo culture)
        {
            return value + " sir";
        }
        // 뷰에서 뷰 모델로 올 때 호출되는 함수
        public object ConvertBack(object value, Type targetType, object parameter, CultureInfo culture)
        {
            throw new NotImplementedException();
        }
    
    }
}
