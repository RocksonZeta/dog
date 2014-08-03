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
        [DllImport("dog32.dll", EntryPoint = "watch32", CharSet = CharSet.Ansi,CallingConvention=CallingConvention.StdCall)]
        public static extern int watch32();

        [DllImport("dog32.dll", EntryPoint = "unwatch32", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern int unwatch32();

        [DllImport("dog32.dll", EntryPoint = "get_system_bits", CharSet = CharSet.Ansi, CallingConvention = CallingConvention.StdCall)]
        public static extern int get_system_bits();

    }
}
