# APIs próprias do WinDurango

Coloque aqui, ou em `apis\` ao lado de `WinDurangoHost.exe`, DLLs próprias que
implementem o contrato em
`projects/WinDurango.Host/include/WinDurango.Host/ApiContract.h`.

O host descobre automaticamente todos os `.dll` dessa pasta. Cada DLL precisa
exportar:

- `WinDurangoApiGetInfo(WinDurangoApiInfo*)`;
- `WinDurangoApiInitialize(const WinDurangoApiHost*)`.

A ABI atual é a versão `1`. DLLs sem esse contrato são rejeitadas. Este diretório
é para APIs do projeto/homebrew; não use bibliotecas do sistema do console.

Um homebrew executável pode ser empacotado como `.wdapp`:

```text
apps\\MeuHomebrew.wdapp\\
  app.exe
  apis\\MinhaApi.dll
  services\\MeuServico.exe
```

O host inicia o `app.exe` e usa a pasta do pacote como diretório de trabalho.
Dashboard e serviços recebem `WINDURANGO_API_ROOT` apontando para `apis\`,
para que o próprio programa possa localizar e carregar explicitamente as APIs
que utiliza.

Para uma DLL fora dessas pastas, carregue-a explicitamente:

```text
WinDurangoHost --load-api C:\caminho\MinhaApi.dll
```

O arquivo externo também precisa exportar o ABI WinDurango.
