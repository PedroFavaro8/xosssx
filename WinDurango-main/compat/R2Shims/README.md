# R2Shims — pack opcional para Windows 7 / Server 2008 R2

As DLLs de compatibilidade (`kernelx`, `d3d11_x`, `winrt_x`, …) importam
api-sets que não existem no kernel 6.1 (`winrt-*`, `memory-l1-1-6/7`,
`file-l1-2-2`, `heap-l2-1-0`, `localization-l1-2-0`, `com-l1-1-1`,
`threadpool-l1-2-0`) e o `d3d12_x` importa `d3d12.dll`. Sem esses arquivos
o loader falha e nada carrega.

Este pack emula o emulável de verdade e falha com graça no resto:

| Arquivo | Conteúdo |
| --- | --- |
| `api-ms-win-core-winrt-string-*` | HSTRING funcional (Reference/Delete/GetRawBuffer) |
| `api-ms-win-core-winrt-l1-1-0` | `RoGetActivationFactory`/`RoActivateInstance` → `E_NOTIMPL` (o C++/WinRT converte em exceção, que o código já trata) |
| `api-ms-win-core-winrt-error-*` | `RoOriginateError`/`RoTransformError` reais; fail-fast encerra, não dialoga |
| `api-ms-win-core-memory-*` | `VirtualAlloc2`/`MapViewOfFile3`/`CreateFileMapping2`/`UnmapViewOfFile2` via APIs antigas |
| `api-ms-win-core-threadpool-*` | `TrySubmitThreadpoolCallback` via `QueueUserWorkItem` (real) |
| `api-ms-win-core-heap/localization/file` | forwards para `KERNEL32` (existem no R2) |
| `d3d12.dll` | só `D3D12SerializeRootSignature` → `E_NOTIMPL` (D3D12 não existe no R2) |

## Adaptação automática (Win10 x R2)

Não há builds separados: no Windows 10+ o schema de api-sets do SO tem
precedência e estes arquivos são ignorados (usa o real); no R2 o schema
não tem as entradas e o loader cai nos arquivos (emula). Onde o SO tem
D3D11/D3D12, usa; onde não tem, o homebrew informa e segue sem GPU.

## Instalação no R2 (offline)

1. Copie o conteúdo de `<build>/r2shim/` para junto do `WinDurangoHost.exe`.
2. Instale o VC Redist correspondente (as DLLs de compat usam CRT dinâmico;
   host e homebrew são estáticos e não precisam).
3. Rode `WinDurangoHost --launch-package apps\Minimal.wdapp`.

> Nunca copie o `d3d12.dll` deste pack para uma máquina com Windows 10+:
> ele sombrearia o D3D12 real. Os api-sets são seguros em qualquer lugar
> (o schema do SO vence), mas o `d3d12.dll` é só para R2.
