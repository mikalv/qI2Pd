#ifndef __NTCPSESSION_H__
#define __NTCPSESSION_H__

#include <QTcpSocket>


const int NTCP_MAX_MESSAGE_SIZE = 16384; 

class NTCPSession
{
  public:
    NTCPSession(QTcpSocket& socket, const i2p::core::RouterInfo * in_RemoteRouterInfo = 0);
    virtual ~NTCPSession () {};

    bool IsEstablished () const { return m_IsEstablished; };
    const i2p::core::RouterInfo& GetRemoteRouterInfo () const { return m_RemoteRouterInfo; };
  
  private:
    void CreateAESKey (uint8_t * pubKey, uint8_t * aesKey);

    //TODO: Split client and server.
    // client
    void SendPhase3 ();
    void HandlePhase1Sent (const boost::system::error_code& ecode,  std::size_t bytes_transferred);
    void HandlePhase2Received (const boost::system::error_code& ecode, std::size_t bytes_transferred);
    void HandlePhase3Sent (const boost::system::error_code& ecode, std::size_t bytes_transferred, uint32_t tsA);
    void HandlePhase4Received (const boost::system::error_code& ecode, std::size_t bytes_transferred, uint32_t tsA);
}


#endif
