// <auto-generated/>
using System;

namespace Telegram.Api.TL
{
	public partial class TLPeerNotifyEventsEmpty : TLPeerNotifyEventsBase 
	{
		public TLPeerNotifyEventsEmpty() { }
		public TLPeerNotifyEventsEmpty(TLBinaryReader from)
		{
			Read(from);
		}

		public override TLType TypeId { get { return TLType.PeerNotifyEventsEmpty; } }

		public override void Read(TLBinaryReader from)
		{
		}

		public override void Write(TLBinaryWriter to)
		{
			to.Write(0xADD53CB3);
		}
	}
}