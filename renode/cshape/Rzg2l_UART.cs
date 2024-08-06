//
// Copyright (c) 2010-2018 Antmicro
//
// This file is licensed under the MIT License.
// Full license text is available in 'licenses/MIT.txt'.
//
using System.Collections.Generic;
using Antmicro.Renode.Peripherals.Bus;
using Antmicro.Renode.Core.Structure.Registers;
using Antmicro.Renode.Core;
using Antmicro.Renode.Logging;

namespace Antmicro.Renode.Peripherals.UART
{
    public class Rzg2l_UART : UARTBase, IDoubleWordPeripheral, IBytePeripheral, IKnownSize
    {
        public Rzg2l_UART(IMachine machine) : base(machine)
        {
            var registersMap = new Dictionary<long, DoubleWordRegister>
            {
                {(long)Registers.SMR, new DoubleWordRegister(this)
                    .WithValueField(0, 1, name: "CKE")
                    .WithFlag(2, name: "TEIE")
                    .WithFlag(3, name: "REIE")
                    .WithFlag(4, name: "RE")
                    .WithFlag(5, name: "TE")
                    .WithFlag(6, name: "RIE")
                    .WithFlag(7, name: "TIE")
                },
                {(long)Registers.SCR, new DoubleWordRegister(this)
                    .WithFlag(0, name: "1", valueProviderCallback: _ => true)
                    .WithFlag(1, name: "2")
                    .WithFlag(2, name: "3")
                    .WithFlag(3, name: "4")
                    .WithFlag(4, name: "RE")
                    .WithFlag(5, name: "RE")
                    .WithFlag(6, name: "RE")
                    .WithFlag(7, name: "RE")
                    .WithValueField(8, 8, name: "Reserved")
                },
            };

            registers = new DoubleWordRegisterCollection(this, registersMap);
        }
 
        public uint ReadDoubleWord(long offset)
        {
            return registers.Read(offset);
        }

        public byte ReadByte(long offset)
        {
            return (byte)ReadDoubleWord(offset);
        }

        public void WriteDoubleWord(long offset, uint value)
        {
            registers.Write(offset, value);
        }
         
        public void WriteByte(long offset, byte value)
        {
            WriteDoubleWord(offset, value);
        }

        public long Size => 0x400;

        // public GPIO IRQ { get; private set; }

        public override Bits StopBits => Bits.One;

        public override Parity ParityBit => Parity.None;

        public override uint BaudRate => 115200;

        protected override void CharWritten()
        {

        }

        protected override void QueueEmptied()
        {

        }


        private readonly DoubleWordRegisterCollection registers;

        private enum Registers : long
        {
            SMR = 0x00,
            BRR = 0x01,
            SCR = 0x02,
            TDR = 0x03,
            SSR = 0x04,
            RDR = 0x05,
            SCMR = 0x06,
            SEMR = 0x07,
            SNFR = 0x08,
            SECR = 0x0D,
            TDRH = 0x0E,
            TDRL = 0x0F,
            RDRH = 0x10,
            RDRL = 0x11,
            MDDR = 0x12,
        }
    }
}
