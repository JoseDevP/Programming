using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GenericAdvanced
{
    public interface IShow<in T>
    {
        public void Show(T element);
    }
}
