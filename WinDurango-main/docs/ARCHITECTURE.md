# WinDurango: arquitetura do projeto

Este documento define o escopo técnico para evoluir o WinDurango como uma
camada de compatibilidade para software Xbox One/ERA no Windows. Ele não é uma
implementação do sistema operacional do Xbox One e não inclui arquivos,
chaves, firmware ou código proprietário da Microsoft.

## Objetivo

Executar software que o usuário possui legalmente, quando possível, por meio
de interfaces compatíveis e componentes reimplementados de forma independente.
O foco inicial é compatibilidade de APIs, gráficos, entrada, áudio,
armazenamento e diagnóstico.

## Camadas

```text
Aplicação ERA/UWP do usuário
        |
WinDurango.WinRT / APIs públicas compatíveis
        |
Serviços de compatibilidade
  KernelX | Storage | Input | Audio | Network | Timing
        |
Backend do Windows
  Win32/UWP | D3D11/D3D12 | XAudio2 | WASAPI | XInput
```

### Responsabilidades

- `WinDurango.WinRT`: ABI/WinRT e fábricas de tipos usadas pela aplicação.
- `WinDurango.KernelX`: memória, threads, sincronização e temporização em
  termos portáveis; não deve fornecer acesso privilegiado ao host.
- `WinDurango.D3D11X` e `WinDurango.D3D12X`: tradução de recursos gráficos
  para Direct3D no Windows.
- `WinDurango.MMDevAPI` e `WinDurango.MFPlat`: áudio e mídia.
- `WinDurango.Common`: configuração, logging e utilitários compartilhados.
- `WinDurango.Host`: executável de diagnóstico, manifesto de módulos e testes
  de carregamento controlado.
- `WinDurango.Testing`: testes de contrato e pequenos programas de validação.

## Regras de compatibilidade

1. O runtime deve funcionar sem uma imagem do `systemupdate`.
2. Componentes proprietários são dependências externas do usuário e não são
   incorporados, extraídos ou redistribuídos pelo projeto.
3. Toda API implementada deve ter um teste mínimo de comportamento e um modo
   de falha explícito quando não for suportada.
4. Estado persistente deve ficar no diretório de configuração do usuário;
   nunca deve gravar em volumes do sistema, firmware ou NAND.
5. O backend gráfico deve ter uma implementação de referência que priorize
   correção e uma camada de diagnóstico antes de otimizações específicas.

## Marcos de implementação

### M1 — runtime observável

- configuração sem perda de dados;
- logging estruturado;
- carregamento controlado de módulos;
- teste de inicialização e relatório de capacidades.

### M2 — contratos básicos

- threads, eventos, timers e filas;
- armazenamento virtual por título;
- input de controle/teclado;
- áudio estereofônico básico.

### M3 — gráficos

- criação de device/context;
- buffers, texturas e shaders suportados;
- captura de frame e validação por imagem;
- testes de sincronização GPU/CPU.

### M4 — compatibilidade por título

- uma aplicação de teste por vez;
- logs reproduzíveis;
- perfis de compatibilidade declarativos;
- nenhuma alteração em firmware ou no sistema do console.

## Fora do escopo

- desbloquear consoles físicos;
- remover assinatura ou secure boot;
- emular ou modificar hypervisor/NAND;
- executar binários não autorizados no Xbox real;
- distribuir jogos, firmware, chaves ou dumps proprietários.

## Critério de qualidade

Uma mudança só deve ser considerada pronta quando compilar em uma build limpa,
passar pelos testes de contrato relevantes, registrar falhas de forma útil e
não alterar arquivos do usuário de maneira silenciosa.
