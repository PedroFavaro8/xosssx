# Minimal Homebrew (.wdapp padrão)

Homebrew de exemplo do WinDurango, empacotado como `.wdapp` e gerado por
padrão em todo build (`apps/Minimal.wdapp` ao lado do `WinDurangoHost`).

```text
apps\Minimal.wdapp\
  app.exe       <- este homebrew (terminal)
  kernelx.dll   <- API de compatibilidade KernelX
  d3d11_x.dll   <- API de compatibilidade D3D11X
```

O programa usa o mínimo das APIs: carrega `kernelx.dll` e `d3d11_x.dll`
em tempo de execução a partir da própria pasta do pacote e exibe no
terminal:

```text
 rodando coisas alem do normal.
```

## Executar

Com o diretório de trabalho na pasta do host (onde está `WinDurangoHost`):

```powershell
WinDurangoHost --launch-package apps\Minimal.wdapp
```

O host define `WINDURANGO_API_ROOT` apontando para `apis\` do pacote,
que o programa exibe no terminal.
