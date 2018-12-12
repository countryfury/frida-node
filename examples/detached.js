'use strict';

const frida = require('..');

async function main() {
  const device = await frida.getUsbDevice();
  const session = await device.attach('Hello');
  session.detached.connect(onDetached);

  console.log('[*] Attached. Press any key to exit.');
  process.stdin.setRawMode(true);
  process.stdin.resume();
  process.stdin.on('data', () => {
    session.detach();
  });
}

  process.stdin.pause();

function onDetached(reason, crash) {
  console.log('[*] onDetached() reason:', reason, 'crash:', crash);
}

main()
  .catch(e => {
    console.error(e);
  });