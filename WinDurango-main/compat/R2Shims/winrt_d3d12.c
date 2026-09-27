/* R2Shims: stub d3d12.dll (so carrega; D3D12 nao existe no R2).
 *
 * ATENCAO: este arquivo JAMAIS vai para o bindir padrao (sombrearia o
 * D3D12 real no Windows 10+). Sai em <build>/r2shim/ e so e copiado
 * manualmente numa maquina R2, onde o objetivo e apenas deixar o
 * d3d12_x.dll carregar e falhar com graca (E_NOTIMPL).
 */
#include <windows.h>
#include <d3d12.h>

HRESULT WINAPI WD_D3D12SerializeRootSignature(const D3D12_ROOT_SIGNATURE_DESC* rootSignature,
                                              D3D_ROOT_SIGNATURE_VERSION version,
                                              ID3DBlob** blob, ID3DBlob** errorBlob) {
    (void)rootSignature;
    (void)version;
    if (blob) {
        *blob = NULL;
    }
    if (errorBlob) {
        *errorBlob = NULL;
    }
    return E_NOTIMPL;
}
