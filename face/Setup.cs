using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Runtime.InteropServices;

namespace face
{
    class Setup
    {
        [DllImport("bark.dll", EntryPoint = "setup", CharSet = CharSet.Ansi,CallingConvention=CallingConvention.StdCall)]
        public static extern int setup();

        [DllImport("bark.dll", EntryPoint = "tearup", CharSet = CharSet.Ansi)]
        public static extern int tearup();
    }
}
