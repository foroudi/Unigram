#pragma once
#include <wrl.h>
#include "Telegram.Api.Native.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using ABI::Telegram::Api::Native::ConnectionType;
using ABI::Telegram::Api::Native::ISendRequestCompletedCallback;
using ABI::Telegram::Api::Native::IRequestQuickAckReceivedCallback;
using ABI::Telegram::Api::Native::TL::ITLObject;

namespace ABI
{
	namespace Telegram
	{
		namespace Api
		{
			namespace Native
			{

				struct ITLBinaryWriterEx;

				MIDL_INTERFACE("AF4AE7B6-02DD-4242-B0EE-92A1F2A9E7D0") IMessageRequest : public IUnknown
				{
				public:
					virtual HRESULT STDMETHODCALLTYPE get_Object(_Out_ ITLObject** value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_MessageId(_Out_ INT64* value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_RawObject(_Out_ ITLObject** value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_MessageSequenceNumber(_Out_ INT32* value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_MessageToken(_Out_ INT32* value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_ConnectionType(_Out_ ConnectionType* value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_DatacenterId(_Out_ UINT32* value) = 0;
					virtual HRESULT STDMETHODCALLTYPE get_Flags(_Out_ RequestFlag* value) = 0;
				};

			}
		}
	}
}


using ABI::Telegram::Api::Native::RequestFlag;
using ABI::Telegram::Api::Native::IMessageRequest;

namespace Telegram
{
	namespace Api
	{
		namespace Native
		{

			class Datacenter;

			class MessageRequest WrlSealed : public RuntimeClass<RuntimeClassFlags<ClassicCom>, IMessageRequest>
			{
				friend class ConnectionManager;

			public:
				//COM exported methods
				IFACEMETHODIMP get_MessageId(_Out_ INT64* value);
				IFACEMETHODIMP get_Object(_Out_ ITLObject** value);
				IFACEMETHODIMP get_RawObject(_Out_ ITLObject** value);
				IFACEMETHODIMP get_MessageSequenceNumber(_Out_ INT32* value);
				IFACEMETHODIMP get_MessageToken(_Out_ INT32* value);
				IFACEMETHODIMP get_ConnectionType(_Out_ ConnectionType* value);
				IFACEMETHODIMP get_DatacenterId(_Out_ UINT32* value);
				IFACEMETHODIMP get_Flags(_Out_ RequestFlag* value);

				//Internal methods
				STDMETHODIMP RuntimeClassInitialize(_In_ ITLObject* object, INT32 token, ConnectionType connectionType, UINT32 datacenterId, _In_ ISendRequestCompletedCallback* sendCompletedCallback,
					_In_ IRequestQuickAckReceivedCallback* quickAckReceivedCallback, RequestFlag flags = RequestFlag::None);

				inline ComPtr<ITLObject> const& GetObject() const
				{
					return m_object;
				}

				inline INT64 GetMessageId() const
				{
					return m_messageId;
				}

				inline INT32 GetMessageSequenceNumber() const
				{
					return m_messageSequenceNumber;
				}

				inline INT32 GetMessageToken() const
				{
					return m_messageToken;
				}

				inline ConnectionType GetConnectionType() const
				{
					return m_connectionType;
				}

				inline UINT32 GetDatacenterId() const
				{
					return m_datacenterId;
				}

				inline RequestFlag Flags() const
				{
					return m_flags;
				}

			private:
				INT64 m_messageId;
				ComPtr<ITLObject> m_object;
				INT32 m_messageSequenceNumber;
				INT32 m_messageToken;
				ConnectionType m_connectionType;
				UINT32 m_datacenterId;
				ComPtr<ISendRequestCompletedCallback> m_sendCompletedCallback;
				ComPtr<IRequestQuickAckReceivedCallback> m_quickAckReceivedCallback;
				RequestFlag m_flags;
			};

		}
	}
}