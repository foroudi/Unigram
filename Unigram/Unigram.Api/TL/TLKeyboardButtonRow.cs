// <auto-generated/>
using System;

namespace Telegram.Api.TL
{
	public partial class TLKeyboardButtonRow : TLObject 
	{
		public TLVector<TLKeyboardButtonBase> Buttons { get; set; }

		public TLKeyboardButtonRow() { }
		public TLKeyboardButtonRow(TLBinaryReader from)
		{
			Read(from);
		}

		public override TLType TypeId { get { return TLType.KeyboardButtonRow; } }

		public override void Read(TLBinaryReader from)
		{
			Buttons = TLFactory.Read<TLVector<TLKeyboardButtonBase>>(from);
		}

		public override void Write(TLBinaryWriter to)
		{
			to.Write(0x77608B83);
			to.WriteObject(Buttons);
		}
	}
}